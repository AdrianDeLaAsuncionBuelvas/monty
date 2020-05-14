#include "monty.h"
glob_var_t Var;

void int_Error(stack_t *head, unsigned int line_number)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer", line_number);
	free(Var.linebuf);
	free(head);
	exit(EXIT_FAILURE);
}
