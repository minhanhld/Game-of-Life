#include "is_alive.h"
#include "grid_operation.h"

void game(int** grid,int **grid2, unint rows, unint cols)
{
    SDL_Window		*window;
    SDL_Renderer	*renderer;

    window = create_window();
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    init_state(renderer, grid, rows, cols);
    unint still_alive = 1;
    int state = 1;
    while(still_alive)
    {
        still_alive = 0;
        if (state)
        {
            for (unint i = 0; i < rows; i++)
            {
                for (unint j = 0; j < cols; j++)
                {
                    if (next_state(grid, i, j))
                    {
                        grid2[i][j] = 1;
                        draw_rect(renderer, j, i, 1);
                        still_alive++;
                    }
                    else
                    {
                        grid2[i][j] = 0;
                        draw_rect(renderer, j, i, 0);
                    }
                }
            }
        }
        else
        {
            for (unint i = 0; i < rows; i++)
            {
                for (unint j = 0; j < cols; j++)
                {
                    if (next_state(grid2, i, j))
                    {
                        grid[i][j] = 1;
                        draw_rect(renderer, j, i, 1);
                        still_alive++;
                    }
                    else
                    {
                        grid[i][j] = 0;
                        draw_rect(renderer, j, i, 0);
                    }
                }
            }

        }
        state = !state;
        sleep(2);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("======== NO MORE CELLS ALIVE ========\n");
}

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        // init the grid
        unint rows = atoi(argv[1]);
        unint cols = atoi(argv[2]);
        int **grid2 = init_board(rows, cols);
        int **grid = init_board(rows,cols);

        // fill the grid at random position
        fill_grid(grid,rows, cols);

        // launch game
        game(grid, grid2, rows, cols);

        // end of game
        free_board(grid, rows); 
    }
    else if (argc == 2)
    {
        // init grid from a file
        int **grid = init_board_preloaded(argv[1]);
        int **grid2 = init_board_preloaded(argv[1]);

        // launch game
        game(grid, grid2, SIZE, SIZE);

        // end of game
        free_board(grid, SIZE);
    }
    else
        errx(1, "error : number of argument different from 2\n");

    return 0;
}
