#include "gameoflife.h"

void fill_grid(int **grid, unint rows, unint cols)
{
    srand(time(NULL));

    for (unint i = 0; i < rows; i++)
    {
       for (unint j = 0; j < cols; j++)
            grid[i][j] = rand()%2;
    }
}

void free_grid(int **grid, unint rows)
{
    for (unint i = 0; i < rows; i++)
        free(grid[i]);
    free(grid);
}

void print_new_grid(unint temp)
{
    for (unint i = 0; i < temp; i++)
    {
        for (unint j = 0; j < temp; j++)
            printf("%d", rand()%2);
        printf("\n");
    }
}
