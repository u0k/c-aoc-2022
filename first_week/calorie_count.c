#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  FILE *fp = fopen(argv[1], "r");
  char chbf[128];
  if (fp == NULL) {
    printf("%s", "FILE NOT FOUND");
    return EXIT_FAILURE;
  }
  u_int32_t sum = 0, max = 0;
  while (fgets(chbf, sizeof(chbf), fp) != NULL) {
    if (chbf[0] == '\n') {
      if (sum > max) {
        max = sum;
      }
      sum = 0;
    }
    sum += atoi(chbf);
  }
  printf("%d\n", max);

  return EXIT_SUCCESS;
}
