#include "monty.h"

/**
 * mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @stack: pointer to stack
 * @line_number: line where opcode can be found
 *
 * Return: no return value
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2, *temp0;

	(void) stack;
	if (globalVar->stackLen < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		close_stream();
		free_token_array();
		free_globalVar();
		exit(EXIT_FAILURE);
	}
	temp1 = globalVar->temp;
	temp2 = temp1->next;
	if (temp1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		close_stream();
		free_token_array();
		free_globalVar();
		exit(EXIT_FAILURE);
	}
	temp2->n = temp2->n % temp1->n;
	temp0 = globalVar->temp;
	globalVar->temp = temp0->next;
	free(temp0);
	globalVar->stackLen -= 1;
}
