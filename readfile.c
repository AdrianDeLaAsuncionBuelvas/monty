#include "monty.h"
glob_var_t Var; /* Global Variable*/



char *readfile(char **av)
{
	stack_t *head = NULL;
	FILE *file;
	size_t buzsize = 0;
	ssize_t characters;
	unsigned int count = 0;

	Var.linebuf = Var.sizbuf = NULL;

	 Var.file = fopen(av[1], "rb");
	if (Var.file == NULL)
	{
		perror("File vacio");
		exit(EXIT_FAILURE);
	}
		characters = getline(&Var.linebuf,  &buzsize, Var.file);
		//stacki(buffer);
		while (characters >= 0)
		{
			Var.sizbuf = NULL;
			count++;
			Var.sizbuf = func_parser(head, count);
			//stacki(buffer); /*aca se envia la cadena a una funcion para procesar la cadena*/
			if (Var.linebuf == NULL)
			{
				characters = getline(&Var.linebuf, &buzsize, Var.file);
			}
			characters = getline(&Var.linebuf,  &buzsize, Var.file);

	}

	fclose(Var.file);
	return (Var.linebuf);
}
