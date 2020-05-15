#include "monty.h"
glob_var_t Var;

/**
 *
 *
 *
 */

void free_stacki(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	head = NULL;
}
