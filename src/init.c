#include "gameoflife.h"

int** init_grid(unint rows, unint cols)
{
	int **grid = malloc(sizeof(int *) * rows);
	for (unint i = 0; i < rows; i++)
			grid[i] = calloc(cols, sizeof(int));
	return grid;
}

int** init_grid_preloaded(char* path)
{
	int fd = open(path, O_RDONLY);
	if (fd == -1)
			errx(1, "open file failed\n");
	// create grid
	int **grid = malloc(sizeof(int *) * SIZE);

	for (unint i = 0; i < SIZE; i++)
	{
			char line;
			grid[i] = calloc(SIZE, sizeof(int));
			unint j = 0;
			while(read(fd, &line, 1) > 0 && j < SIZE)
			{
					grid[i][j] = line-'0';
					j++;
			}
	}
	close(fd);
	return grid;
}

void	init_state(SDL_Renderer *r, int **grid, unint rows, unint cols)
{
	for (unint i = 0; i < rows; i++)
	{
		for (unint j = 0; j < cols; j++)
		{
			if (grid[i][j] == 1)
				draw_rect(r, j, i, 1);
		}
	}
	SDL_RenderPresent(r);
}

