#include "monty.h"

/**
 * pop - removes top element from the stack
 * @stack: points to stack
 * @line_number: line number where pop is called
 *
 * Return: no return value;
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void) stack;
	if (globalVar->temp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		close_stream();
		free_token_array();
		free_globalVar();
		exit(EXIT_FAILURE);
	}
	ptr = globalVar->temp;
	globalVar->temp = ptr->next;
	free(ptr);
}

