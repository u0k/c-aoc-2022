#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  FILE *fp = fopen(argv[1], "r");
  char chbf[128];
  u_int32_t top_sums[3] = {0, 0, 0};
  if (fp == NULL) {
    printf("%s", "FILE NOT FOUND");
    return EXIT_FAILURE;
  }
  u_int32_t sum = 0, max = 0;
  while (fgets(chbf, sizeof(chbf), fp) != NULL) {
    if (chbf[0] == '\n') {
      if (sum > top_sums[0]) {
        top_sums[0] = sum;
      } else if (sum > top_sums[1]) {
        top_sums[1] = sum;
      } else if (sum > top_sums[2]) {
        top_sums[2] = sum;
      }
      if (sum > max) {
        max = sum;
      }
      sum = 0;
    }
    sum += atoi(chbf);
  }
  printf("%d\n", max);
  printf("%d\n", top_sums[0] + top_sums[1] + top_sums[2]);

  return EXIT_SUCCESS;
}
