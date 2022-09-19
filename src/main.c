#include "gameoflife.h"

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		if (strcmp(argv[1], "-t") == 0)
		{
				unint temp = atoi(argv[2]);
				print_new_grid(temp);
		}
		else
			game(atoi(argv[1]), atoi(argv[2]), 0);
	}
	else if (argc == 4)
	{
		if (strcmp(argv[1], "-g"))
					errx(1, "invalid option");
		game(atoi(argv[2]), atoi(argv[3]), 1);
	}
	else
		errx(1, "error : number of argument different from 2");
	return (0);
}
