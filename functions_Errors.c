#include "monty.h"
glob_var_t Var;

/**
 *
 *
 *
 */

void int_Error(stack_t *head, unsigned int number)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer", number);
	free(Var.sizbuf);
	fclose(Var.file);
	free(Var.linebuf);
	free_stacki(head);
	exit(EXIT_FAILURE);
}


/**
 *
 *
 *
 */

void parser_line(ssize_t characters)
{
	if (characters == -1)
	{
		free(Var.linebuf);
		fclose(Var.file);
		free(Var.sizbuf);
		exit(0);
	}
}


/**
 *
 *
 *
 */

void check_opc_code(int line_check, unsigned int line_num, stack_t *head)
{
	if (line_check == 0)
	{
		check_instructions(line_num);
		free_stacki(head);
		exit(EXIT_FAILURE);
	}
}

/**
 *
 *
 *
 */

void check_instructions(unsigned int ln)
{
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", ln, Var.sizbuf);
}
