#include "is_alive.h"

int neighbors_around(int **grid, unint row, unint col, unint rows, unint cols)
{
    int alive_around = 0;

    // all cell around position (row, col)
    if ((int)(row-1) >= 0 && (int)(col-1) >= 0)
        alive_around += grid[row-1][col-1] == 1;

    if ((int)(row-1) >= 0 && (int)(col) >= 0)
        alive_around += grid[row-1][col] == 1;

    if ((int)(row-1) >= 0 && col+1 < cols)
        alive_around += grid[row-1][col+1] == 1;

    if ((int)(row) >= 0 && (int)(col-1) >= 0)
        alive_around += grid[row][col-1] == 1;

    if ((int)(row) >= 0 && col+1 < cols)
        alive_around += grid[row][col+1] == 1;

    if (row+1 < rows && (int)(col-1) >= 0)
        alive_around += grid[row+1][col-1] == 1;

    if (row+1 < rows && (int)(col) >= 0)
        alive_around += grid[row+1][col] == 1;

    if (row+1 < rows && col+1 < cols)
        alive_around += grid[row+1][col+1] == 1;

    return alive_around;
}

int next_state(int **grid, unint row, unint col, unint rows, unint cols)
{
    int alive_around = neighbors_around(grid, row, col, rows, cols);

    // Any live cell with two or three live neighbours survives
    if (grid[row][col] == 1 && (alive_around == 2 || alive_around == 3))
        return 1;
    
    // Any dead cell with three live neighbours becomes a live cell
    if (grid[row][col] == 0 && alive_around == 3)
        return 1;

    // All other live cells die in the next generation. Similarly, all other dead cells stay dead
    return 0;
}
