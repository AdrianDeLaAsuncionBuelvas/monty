#include "monty.h"
glob_var_t Var;

/**
*func_code_push - Will data if the word is push.
*@stack: stack that contain the data
*@line_number: received the number of de line
*/


void func_code_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	(void)line_number;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		free(*stack);
		exit(EXIT_FAILURE);
	}

	new->n = Var.node_num;
	new->next = NULL;
	new->prev = NULL;

	if (*stack)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}

	*stack = new;

}

/**
*func_code_pall - Will data if the word is pall.
*@stack: stack that contain the data
*@line_number: received the number of de line
*/


void func_code_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	size_t count = 0;
	(void)line_number;

	if (!stack)
	{
		free(stack);
		exit(EXIT_FAILURE);
	}
	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
		count++;
	}
}

