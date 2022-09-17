#include "fill_grid.h"

void fill_grid(unint** grid, unint rows, unint cols)
{
    srand(time(NULL));

    unint number_lives = (rows+cols) / 4;
    for (unint i = 0; i < number_lives; i++)
    {
        int rand_a, rand_b;
        while(1)
        {
            rand_a = rand()%rows;
            rand_b = rand()%cols;
            if (!grid[rand_a][rand_b])
                break;
        }
        grid[rand_a][rand_b] = 1;
    }

}
