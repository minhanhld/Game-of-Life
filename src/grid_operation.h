#ifndef GRID_OPERATION_
#define GRID_OPERATION_

// constant
#define SIZE 50

// include
#include "is_alive.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// functions
void fill_grid(int **grid, unint row, unint col);
void print_board(int **grid, unint rows, unint cols);
void free_board(int **grid, unint rows);
int** init_board(unint rows, unint cols);
int** init_board_preloaded(char* path);

#endif
