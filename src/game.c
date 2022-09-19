#include "gameoflife.h"

void launch(int** grid,int **grid2, unint rows, unint cols, int opt)
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	int				state;
	unint			still_alive;

	window = create_window(rows, cols);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	still_alive = 1;
	state = 1;
	if (opt)
			draw_lines(renderer, rows, cols);
	init_state(renderer, grid, rows, cols);
	while(still_alive)
	{
		still_alive = 0;
		if (state)
			check_then_render(grid, grid2, rows, cols, renderer, &still_alive);
		else
			check_then_render(grid2, grid, rows, cols, renderer, &still_alive);
		SDL_Delay(50);
		state = !state;
	}
	clean(window, renderer);
	printf("======== NO MORE CELLS ALIVE ========\n");
}

void	game(unint rows, unint cols, int opt)
{
	int	**grid;
	int	**grid2;

	grid = init_grid(rows, cols);
	grid2 = init_grid(rows, cols);
	fill_grid(grid, rows, cols);
	launch(grid, grid2, rows, cols, opt);
	free_grid(grid, rows);
}
