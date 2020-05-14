#include "monty.h"
glob_var_t Var;

void int_Error(stack_t *head, unsigned int line_number)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer", line_number);
	free(Var.linebuf);
	free(head);
	exit(EXIT_FAILURE);
}

void parser_line(ssize_t characters)
{
	if (characters == -1)
	{
		free(Var.linebuf);
		fclose(Var.file);
		exit(0);
	}
}
