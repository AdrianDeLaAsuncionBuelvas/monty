#include "monty.h"
glob_var_t Var;



int get_functions(stack_t **head, unsigned int line_number)
{
	unsigned int i;

	instruction_t func_code[] = {
		{"push", func_code_push},
		{"pall", func_code_pall},
		{NULL, NULL}
	};
	i = 0;
	if (Var.sizbuf[0] == '#')
	{
		//func_code[1].f(head, line_number);
		return (1);
	}
	while (i != 2)
	{
		if (!(strcmp(func_code[i].opcode, Var.sizbuf)))
		{
			func_code[i].f(head, line_number);
			break;
		}
		i++;
	}
	if (i == 2)
		return (0);

	return (1);
}
