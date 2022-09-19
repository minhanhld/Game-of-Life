#ifndef GAMEOFLIFE_H
# define GAMEOFLIFE_H

# define SIZE 50

# include <SDL2/SDL.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <time.h>
# include <err.h>
# include <stdio.h>
# include <stdlib.h>

typedef size_t	unint;

void		fill_grid(int **grid, unint row, unint col);
void		print_board(int **grid, unint rows, unint cols);
void		free_grid(int **grid, unint rows);
int			init_SDL(void);
void		draw_rect(SDL_Renderer *r, int x, int y, int color);
SDL_Window	*create_window(unint rows, unint cols);
void		init_state(SDL_Renderer *r, int **grid, unint rows, unint cols);
int**		init_grid(unint rows, unint cols);
int**		init_grid_preloaded(char* path);
void		print_new_grid(unint temp);
void		draw_lines(SDL_Renderer *r, unint rows, unint cols);
int			next_state(int **grid, unint row, unint col, unint rows, unint cols);
void		check_then_render(int **grid, int **grid2, unint r, unint c, SDL_Renderer *ren, unint *sa);
void		launch(int **grid, int **grid2, unint rows, unint cols, int opt);
void		game(unint rows, unint cols, int opt);
void		clean(SDL_Window *w, SDL_Renderer *r);

#endif
