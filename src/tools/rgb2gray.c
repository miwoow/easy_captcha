#include "rgb2gray.h"

int
rgb2gray(uint8_t *src, size_t src_len, uint8_t *dst)
{
  float result = 0.0;
  uint8_t num = 0;
  int i=0;

  for(i=0; i< src_len / 3; i++) {
    result = 0.0;
    num = *(src + i * 3);
    result += 0.29900 * num;
    num = *(src + i * 3 + 1);
    result += 0.58700 * num;
    num = *(src + i * 3 + 2);
    result += 0.11400 * num;
    dst[i] = (uint8_t)result;
  }
  return 0;
}
