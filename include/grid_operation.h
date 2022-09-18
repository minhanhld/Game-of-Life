#ifndef GRID_OPERATION_
#define GRID_OPERATION_

// constant
#define SIZE 50

// include
#include "is_alive.h"
#include <SDL2/SDL.h>

// functions
void fill_grid(int **grid, unint row, unint col);
void print_board(int **grid, unint rows, unint cols);
void free_board(int **grid, unint rows);
int** init_board(int **grid, unint rows, unint cols);
int	init_SDL(void);
void	draw_rect(SDL_Renderer *r, int x, int y, int color);
SDL_Window	*create_window(void);
void	init_state(SDL_Renderer *r, int **grid, unint rows, unint cols);

#endif
