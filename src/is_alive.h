#ifndef IS_ALIVE_
#define IS_ALIVE_

// includes
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <SDL.H>

// struct, typedef, enum etc
typedef size_t unint;

// functions
int is_alive(int **grid, int row, int col);
int is_dead(int **grid, int row, int col);

#endif
