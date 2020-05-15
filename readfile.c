#include "monty.h"
glob_var_t Var; /* Global Variable*/

/**
*readfile - read file digited in console.
*@filename: Directory and name of file.
*Return: a pointer to a line of characters.
*/

char *readfile(char *filename)
{
	stack_t *head = NULL;
	size_t buzsize = 0;
	ssize_t characters;
	unsigned int count = 0;

	Var.linebuf = Var.sizbuf = NULL;

	Var.file = fopen(filename, "rb");
	if (!Var.file)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	characters = getline(&Var.linebuf,  &buzsize, Var.file);
	parser_line(characters);
	while (characters >= 0)
	{
		Var.sizbuf = NULL;
		count++;
		Var.sizbuf = func_parser(head, count);

		if (Var.linebuf == NULL)
		{
			characters = getline(&Var.linebuf, &buzsize, Var.file);
			continue;
		}
		get_functions(&head, count);
		characters = getline(&Var.linebuf,  &buzsize, Var.file);

	}

	fclose(Var.file);
	return (Var.linebuf);
}

