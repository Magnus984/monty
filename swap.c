#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to stack.
 * @line_number: line where swap function is
 *
 * Return: no return value
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	(void) stack;
	if (globalVar->stackLen <2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		close_stream();
		free_token_array();
		free_globalVar();
		exit(EXIT_FAILURE);
	}
	temp1 = globalVar->temp;
	temp2 = temp1->next;
	temp1->next = temp2->next;
	if (temp1->next)
		temp1->next->prev = temp1;
	temp2->next = temp1;
	temp1->prev = temp2;
	temp2->prev = NULL;
	globalVar->temp = temp2;
}
