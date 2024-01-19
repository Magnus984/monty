#include "monty.h"

/**
 * pint - prints value at top of stack
 * @stack: pointer to stack
 * @line_number: line where function is called
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (globalVar->temp == NULL)
	{
		fprintf(stderr, "L%d: can't print, stack empty\n", line_number);
		close_stream();
		free_token_array();
		free_globalVar();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", globalVar->temp->n);
}
