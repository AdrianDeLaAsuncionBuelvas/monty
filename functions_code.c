#include "monty.h"
glob_var_t Var;

/**
 * func_code_push - Will data if the word is push.
 * @stack: stack that contain the data
 * @ln: received the number of de line
 */


void func_code_push(stack_t **stack, unsigned int ln __attribute__((unused)))
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free(Var.linebuf);
		fclose(Var.file);
		free_stacki(*stack);
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
 * func_code_pall - Will data if the word is pall.
 * @stack: stack that contain the data
 * @ln: received the number of de line
 */


void func_code_pall(stack_t **stack, unsigned int ln __attribute__((unused)))
{
	stack_t *node = *stack;

	if (!stack)
	{
		free(stack);
		exit(EXIT_FAILURE);
	}
	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}


/**
 * func_code_pop - removes the top element of the stack.
 * @stack: stack that contain the data
 * @ln: received the number of de line
 */

void func_code_pop(stack_t **stack, unsigned int ln __attribute__((unused)))
{
	stack_t *node = *stack;

	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}

	*stack = node->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(node);
}

/**
 * func_code_pint -  prints the value at the top of the stack.
 * @stack: stack that contain the data
 * @ln: received the number of de line
 */

void func_code_pint(stack_t **stack, unsigned int ln)
{
	stack_t *node = *stack;

	if (node)
	{
		printf("%d\n", node->n);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
}
