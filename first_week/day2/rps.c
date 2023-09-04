#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int point_table[3][3] = {{4, 8, 3}, {1, 5, 9}, {7, 2, 6}};
  FILE *fp = fopen(argv[1], "r");
  char chbf[128];

  if (fp == NULL) {
    printf("%s", "FILE NOT FOUND\n");
    return EXIT_FAILURE;
  }
  uint32_t points = 0;
  uint32_t ultra_secret_points = 0;
  while (fgets(chbf, sizeof(chbf), fp) != NULL) {
    int op_move = chbf[0];
    int my_move = chbf[2];

    op_move -= 'A';
    my_move -= 'X';

    // If draw
    if (my_move == 1) {
      // Pick the same move as opponent
      ultra_secret_points += point_table[op_move][op_move];
    } else if (my_move == 0) // If loss
    {
      // Pick the move that's two moves ahead of opponent R->S, P->R, S->P
      ultra_secret_points += point_table[op_move][(op_move + 2) % 3];
    } else { // Have to win, pick the move that's one move ahead R->P, P->S,
             // S->R
      ultra_secret_points += point_table[op_move][(op_move + 1) % 3];
    }
    points += point_table[op_move][my_move];
  }
  printf("%d\n", points);
  printf("%d\n", ultra_secret_points);
  return EXIT_SUCCESS;
}
