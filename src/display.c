#include "gameoflife.h"

void	draw_rect(SDL_Renderer *r, int x, int y, int color)
{
	SDL_Rect	*rect;

	rect = malloc(sizeof(SDL_Rect));
	if (!rect)
		return ;
	rect->w = 10;
	rect->h = 10;
	rect->x = 11 * x + 1;
	rect->y = 11 * y + 1;
	if (color == 1)
		SDL_SetRenderDrawColor(r, 255, 255, 255, 1);
	else if (color == 0)
		SDL_SetRenderDrawColor(r, 0, 0, 0, 1);
	SDL_RenderFillRect(r, rect);
	free(rect);
}

void	draw_lines(SDL_Renderer *r, unint rows, unint cols)
{
	unint	i;
	unint	k;

	i = -1;
	k = 0;
	SDL_SetRenderDrawColor(r, 231, 109, 137, 1);
	while (++i < cols + 1)
	{
		SDL_RenderDrawLine(r, k, 0, k, 11 * rows);
		k += 11;
	}
	i = -1;
	k = 0;
	while (++i < rows + 1)
	{
		SDL_RenderDrawLine(r, 0, k, 11 * cols, k);
		k += 11;
	}
	SDL_RenderPresent(r);
}

void	check_then_render(int **grid, int **grid2, unint rows, unint cols, SDL_Renderer *r, unint *still_alive)
{
	for (unint i = 0; i < rows; i++)
	{
		for (unint j = 0; j < cols; j++)
		{
			if (next_state(grid, i, j, rows, cols))
			{
				grid2[i][j] = 1;
				draw_rect(r, j, i, 1);
				*still_alive = *still_alive + 1;
			}
			else
			{
				grid2[i][j] = 0;
				draw_rect(r, j, i, 0);
			}
		}
	}
	SDL_RenderPresent(r);
}
