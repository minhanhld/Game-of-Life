#include "grid_operation.h"

int	init_SDL(void)
{
	int	init;

	init = SDL_Init(SDL_INIT_VIDEO);
	if (init)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

SDL_Window	*create_window(void)
{
	SDL_Window*	window;

	window = SDL_CreateWindow("Window", 0, 0, 1920, 1080, SDL_WINDOW_SHOWN);
	return (window);
}

void	draw_rect(SDL_Renderer *r, int x, int y, int color)
{
	SDL_Rect	*rect;

	rect = malloc(sizeof(SDL_Rect));
	if (!rect)
		return ;
	rect->w = 1;
	rect->h = 1;
	rect->x = 1 * x;
	rect->y = 1 * y;
	if (color == 1)
		SDL_SetRenderDrawColor(r, 255, 255, 255, 1);
	else if (color == 0)
		SDL_SetRenderDrawColor(r, 0, 0, 0, 1);
	SDL_RenderFillRect(r, rect);
	free(rect);
}
