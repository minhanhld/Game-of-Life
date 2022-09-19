#include "gameoflife.h"

int	is_strdigit(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	check_argv(int argc, char *argv[], int i)
{
	while (i < argc)
	{
		if (!is_strdigit(argv[i]) || atoi(argv[1]) > 100)
		{
			errx(1, "arguments are either not numbers or too large");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_args(int argc, char *argv[])
{
	if (argc == 3)
		return (check_argv(argc, argv, 1));
	else if (argc == 4)
	{
		if (strcmp(argv[1], "-g"))
			errx(1, "invalid option");
		return (check_argv(argc, argv, 2));
	}
	else
		errx(1, "error : invalid number of arguments");
	return (0);
}
