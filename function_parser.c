#include "monty.h"
glob_var_t Var;

char *func_parser(stack_t *head, unsigned int num)
{
	char *delim = "\n";
	char *token = NULL, *array = NULL;
	int i = 0;
			 printf("son iguales");

	 token = strtok(Var.linebuf, delim);
	 if (token == NULL)
		 return (NULL);
	 if (strcmp(token, delim) == 0)
	 {
	        array = strtok(NULL, delim);
		if (array == NULL)
			int_Error(head, num);
		/**array[i] = token;
		 array = malloc(sizeof(head) + BUFFSIZE);
	if(!array)
	perror("Error: malloc failed"), exit(EXIT_FAILURE);

	array[i] = token;*/

	while (array[i])
	{
		if (i == 0 && array[i] == '-')
		{
			i++;
			continue;
		}
		if (array[i] >= 48 && array[i] <= 57)
		{
			i++;
			continue;
		}
		else
		{
			int_Error(head, num);
		}

	}
	Var.node_num = atoi(array);
	 }
	 return (token);
}
