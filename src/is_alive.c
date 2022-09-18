#include "is_alive.h"

/*Checking for neighbors around one cell in 1st ft
//Then checking according to the rules of the game
//and returning the corresponding value for the
//next generation.
 */

int neighbors_around(int **grid, unint row, unint col, unint rows, unint cols)
{
		int alive_around;

	alive_around = 0;
	if ((int)row - 1 >= 0 && (int)col - 1 >= 0)
		alive_around += grid[row - 1][col - 1] == 1;
	if ((int)row - 1 >= 0 && (int)col >= 0)
			alive_around += grid[row - 1][col] == 1;
	if ((int)row - 1 >= 0 && col + 1 < cols)
			alive_around += grid[row - 1][col + 1] == 1;
	if ((int)row >= 0 && (int)col - 1 >= 0)
			alive_around += grid[row][col - 1] == 1;
	if ((int)row >= 0 && col + 1 < cols)
			alive_around += grid[row][col + 1] == 1;
	if (row + 1 < rows && (int)col - 1 >= 0)
			alive_around += grid[row + 1][col - 1] == 1;
	if (row + 1 < rows && (int)col >= 0)
			alive_around += grid[row + 1][col] == 1;
	if (row + 1 < rows && col + 1 < cols)
			alive_around += grid[row + 1][col + 1] == 1;
	return (alive_around);
}

int next_state(int **grid, unint row, unint col, unint rows, unint cols)
{
	int alive_around;

	alive_around = neighbors_around(grid, row, col, rows, cols);
	if (grid[row][col] == 1 && (alive_around == 2 || alive_around == 3))
			return (1);
	if (grid[row][col] == 0 && alive_around == 3)
			return (1);
	return (0);
}
