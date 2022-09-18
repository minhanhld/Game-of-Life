#include "grid_operation.h"

void fill_grid(int **grid, unint rows, unint cols)
{
    srand(time(NULL));

    unint number_lives = (rows+cols)*5;
    for (unint i = 0; i < number_lives; i++)
    {
        int rand_a, rand_b;
        // fill grid at random position
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

void print_board(int **grid, unint rows, unint cols)
{
    // print top border
    for (unint i = 0; i < cols; i++)
        printf("=");
    printf("\n");

    // print content
    for (unint i = 0; i < rows; i++)
    {
        for (unint j = 0; j < cols; j++)
            printf("%u", grid[i][j]);
        printf("\n");
    }
    
    // print bottom border
    for (unint i = 0; i < cols; i++)
        printf("=");
    printf("\n");
}