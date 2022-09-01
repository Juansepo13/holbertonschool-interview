#ifndef Sandpiles
#define Sandpiles

#include <stdio.h>
#include <stdlib.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
static void print_grid(int grid[3][3]);
int check_stable_sandpile(int grid1[3][3]);
void topple_sandpile(int grid1[3][3]);

#endif /* Sandpiles */
