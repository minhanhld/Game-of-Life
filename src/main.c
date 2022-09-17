#include "is_alive.h"
#include "fill_grid.h"

void game(int** grid, unint rows, unint cols)
{
    // infinite loop to launch the game
    while(1)
    {
        for (unint i = 0; i < rows; i++)
        {
            for (unint j = 0; j < cols; j++)
            {
                if (is_alive(grid, i, j))
                    grid[i][j] = 1;
                else
                    grid[i][j] = 0;
            }
        }
        sleep(1);
    }
}

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        // init the grid
        unint rows = atoi(argv[1]);
        unint cols = atoi(argv[2]);

        unint **grid = malloc(sizeof(size_t*) * rows);
        for (unint i = 0; i < cols; i++)
            grid[i] = calloc(sizeof(size_t) * cols);
        
        // fill the grid at random position
        fill_grid(grid, rows, cols);

        // launch game
        game(grid, rows, cols);
    }
    else
        errx(1, "error : number of argument different from 2\n");
    return 0;
}
