#include "gameoflife.h"

int main(int argc, char *argv[])
{
	if (!check_args(argc, argv))
		return (0);
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
		game(atoi(argv[2]), atoi(argv[3]), 1);
	return (0);
}
