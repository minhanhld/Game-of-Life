#include "is_alive.h"
#include "grid_operation.h"

void game(int** grid, unint rows, unint cols)
{
    unint still_alive = 1;

    // infinite loop to launch the game
    while(still_alive)
    {
        still_alive = 0;
        print_board(grid, rows, cols);
        for (unint i = 0; i < rows; i++)
        {
            for (unint j = 0; j < cols; j++)
            {
                if (next_state(grid, i, j))
                {
                    grid[i][j] = 1;
                    still_alive++;
                }
                else
                    grid[i][j] = 0;
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
        init_board(grid,rows,cols);
                
        // fill the grid at random position
        fill_grid(grid, rows, cols);

        // launch game
        game(grid, rows, cols);

        // end of game
        free_board(grid, rows); 
    }
    /*else if (argc == 2)
    {
        int **grid;
        init_board_preloaded(grid, argv[1]);
    }*/
    else
        errx(1, "error : number of argument different from 2\n");
    return 0;
}
