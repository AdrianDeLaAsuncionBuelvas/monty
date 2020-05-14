#include "monty.h"

int main(int ac, char **av)
{
	char *file;
	file = av[1];
	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	readfile(file);
	return (0);
}
