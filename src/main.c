#include "is_alive.h"
#include "grid_operation.h"

void game(int** grid, unint rows, unint cols)
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;

	window = create_window();
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	init_state(renderer, grid, rows, cols);
    unint still_alive = 1;
    // infinite loop to launch the game
    while(still_alive)
    {
        still_alive = 0;
        for (unint i = 0; i < rows; i++)
        {
            for (unint j = 0; j < cols; j++)
            {
                if (next_state(grid, i, j))
                {
                    draw_rect(renderer, j, i, 1);
                    still_alive++;
                }
                else
                    draw_rect(renderer, j, i, 0);
            }
        }
        sleep(1);
    }

    printf("======== NO MORE CELLS ALIVE ========\n");
}

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        // init the grid
        unint rows = atoi(argv[1]);
        unint cols = atoi(argv[2]);
        int **grid = NULL;
        grid = init_board(rows,cols);
                
        // fill the grid at random position
        fill_grid(grid,rows, cols);

        // launch game
        game(grid, rows, cols);

        // end of game
        free_board(grid, rows); 
    }
    else if (argc == 2)
    {
        // init grid from a file
        int **grid = NULL;
        grid = init_board_preloaded(argv[1]);

        // launch game
        game(grid, SIZE, SIZE);

        // end of game
        free_board(grid, SIZE);
    }
    else
        errx(1, "error : number of argument different from 2\n");

    return 0;
}
