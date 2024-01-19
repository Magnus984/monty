#include "monty.h"

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack.
 *
 * Return: no return value
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	(void) stack;
	(void) line_number;

	if (!(globalVar->temp))
	{
		ptr = globalVar->temp;
		while (ptr != NULL)
		{
			printf("%d\n", ptr->n);
			ptr = ptr->next;
		}
	}
}
