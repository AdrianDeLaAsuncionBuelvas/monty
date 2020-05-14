#include "monty.h"

int main(int ac __attribute__((unused)), char **av)
{
	char *file;
	file = readfile(av);
	printf("Desde el Main %s\n", file);

	return (0);
}
