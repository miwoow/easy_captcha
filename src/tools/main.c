#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//#include <rgb2gray.h>

int
main(int argc, char* argv[])
{
  FILE *pic_handler = NULL, *output_handler = NULL;
  int i=0, j=0;
  char *file_names[4] = {"one.dat", "two.dat", "three.dat", "four.dat"};
  int file_name_index = 0;
  uint8_t data[10][120] = {0};
  int num = 0;

  pic_handler = fopen(argv[1], "rb");
  fseek(pic_handler, 0x36, SEEK_SET);
  fread(data, 1, 1200, pic_handler);
  for(i=0; i<10; i++) {
    for(j=0; j<120; j++) {
      if (j%30 == 0) {
	output_handler = fopen(file_names[j/30], "ab");
	printf("j=%d, file_name: %s\n", j, file_names[j/30]);
	fwrite(&(data[i][j]), 1, 30, output_handler);
	fclose(output_handler);
      }
    }
  }
  fclose(pic_handler);
  return 0;
}
