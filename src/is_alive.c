#include "is_alive.h"

int neighbors_around(int **grid, unint row, unint col, int *alived_around, int*dead_around)
{
    // all cell around position (row, col)
    if ((int)(row-1) >= 0 && (int)(col-1) >= 0)
    {
        alive_around += grid[row-1][col-1] == 1;
        dead_around += grid[row-1][col-1] == 0;
    }

    if ((int)(row-1) >= 0 && (int)(col) >= 0)
    {
        alive_around += grid[row-1][col] == 1;
        dead_around += grid[row-1][col] == 0;
    }

    if ((int)(row-1) >= 0 && (int)(col+1) <= 8)
    {
        alive_around += grid[row-1][col+1] == 1;
        dead_around += grid[row-1][col+1] == 0;

    }

    if ((int)(row) >= 0 && (int)(col-1) >= 0)
    {
        alive_around += grid[row][col-1] == 1;
        dead_around += grid[row][col-1] == 0;
    
    }
    if ((int)(row) >= 0 && (int)(col+1) <= 8)
    {
        alive_around += grid[row][col+1] == 1;
        dead_around += grid[row][col+1] == 0;

    }
    if ((int)(row+1) <= 8 && (int)(col-1) >= 0)
    {
        alive_around += grid[row+1][col-1] == 1;
        dead_around += grid[row+1][col-1] == 0;
    
    }
    if ((int)(row+1) <= 8 && (int)(col) >= 0)
    {
        alive_around += grid[row+1][col] == 1;
        dead_around += grid[row+1][col] == 0;

    }
    if ((int)(row+1) <= 8 && (int)(col+1) <= 8)
    {
        alive_around += grid[row+1][col+1] == 1;
        dead_around += grid[row+1][col+1] == 0;

    }
    return number_around;
}

int is_alive(unint **grid, unint row, unint col)
{
    int number_around = neighbors_around(grid, row, col, 1);
    return number_around 
}

int is_dead(unint **grid, unint row, unint col)
{

}

int next_state(unint **grid, unint row, unint col)
{

}

