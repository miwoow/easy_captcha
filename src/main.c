#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>

uint8_t num_data[10][300];

void
load_data()
{
  char data_path[128] = {0};
  uint8_t data[300] = {0};
  int i=0, j=0;
  FILE *data_file_handler = NULL;

  for(i=0; i< 10; i++) {
    bzero(data_path, 128);
    snprintf(data_path, 127, "./data/%d.dat", i);
    data_file_handler = fopen(data_path, "rb");
    fread(data, 1, 300, data_file_handler);
    for(j=0; j< 300; j++) {
      if (data[j] == 0xee) {
	data[j] = 0x00;
      } else {
	data[j] = 0x01;
      }
    }
    memcpy(num_data[i], data, 300);
    fclose(data_file_handler);
  }
}

int
main(int argc, char *argv[])
{
  load_data();

  FILE *pic_handler = NULL;
  uint8_t data[10][120] = {0};
  uint8_t pic_data[4][300] = {0};
  int i=0, j=0;

  pic_handler = fopen(argv[1], "rb");
  fseek(pic_handler, 0x36, SEEK_SET);
  fread(data, 1, 1200, pic_handler);
  fclose(pic_handler);

  for(i=0; i<1200; i++) {
    if (data[i/120][i%120] == 0xee) {
      data[i/120][i%120] = 0x00;
    } else {
      data[i/120][i%120] = 0x01;
    }
  }
  
  for(i=0; i< 10; i++) {
    for(j=0; j<120; j++) {
      if (j%30 == 0) {
	memcpy(&(pic_data[j/30][i*30]), &(data[i][j]), 30);
      }
    }
  }

  for(i=0; i<4; i++) {
    for(j=0; j<10; j++) {
      if (memcmp(pic_data[i], num_data[j], 300) == 0) {
	printf("%d\t", j);
	break;
      }
    }
  }

  printf("\n");
  return 0;
}
