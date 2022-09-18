#include "gol.h"
int	setWindowColor(SDL_Renderer *renderer, SDL_Color color)
{
	if (SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) < 0)
		return (-1);
	if (SDL_RenderClear(renderer) < 0)
		return (-1);
	return (0);
}

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	int init = SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window = NULL;
	SDL_Color white = {255, 255, 255, 1};
	if (init)
		return (EXIT_FAILURE);
	window = SDL_CreateWindow("Window", 0, 0, 500, 500, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//	setWindowColor(renderer, white);
//	SDL_RenderPresent(renderer);
	//SDL_Rect rect = {100, 100, 100, 100};
	SDL_Rect rect[50];
	size_t i = 0;
	for(i = 0; i < 50; i++)
	{
	    rect[i].w = 50;
	    rect[i].h = 50;
	    rect[i].x = 100 * (i % 5) + 50 * ((i / 5) % 2);
	    rect[i].y = 50 * (i / 5);
	}
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
	SDL_RenderFillRects(renderer, rect, 50);
	//SDL_RenderPresent(renderer);

	SDL_RenderPresent(renderer);

	//SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);



	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

