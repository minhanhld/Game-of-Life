#ifndef IS_ALIVE_
#define IS_ALIVE_

// includes
#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <time.h>
#include <unistd.h>
#include <SDL2/SDL.h>

// struct, typedef, enum etc
typedef size_t unint;

// functions
int next_state(int **grid, unint row, unint col, unint rows, unint cols);

#endif
