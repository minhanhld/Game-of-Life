#include "gameoflife.h"

int	init_SDL(void)
{
	int	init;

	init = SDL_Init(SDL_INIT_VIDEO);
	if (init)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

SDL_Window	*create_window(unint rows, unint cols)
{
	SDL_Window*	window;

	window = SDL_CreateWindow("Window", (1920 / 2) - (11 * cols + 2) / 2, (1080 / 2) - (11 * rows + 2) / 2, 11 * cols + 2, 11 * rows + 2, SDL_WINDOW_SHOWN);
	return (window);
}

void	clean(SDL_Window *w, SDL_Renderer *r)
{
	SDL_DestroyRenderer(r);
	SDL_DestroyWindow(w);
	SDL_Quit();
}
