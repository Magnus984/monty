#include "monty.h"

/**
 * push - inserts element in stack
 * @stack: pointer to stack
 * @line_number: number of line read
 *
 * Return: no return value
 */
void push(stack_t **stack, unsigned int line_number)
{
	if (globalVar->tokenNumber <= 1 || !(is_valid_number(globalVar->tokens[1])))
	{
		free_globalVar();
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		fprintf(stderr, "malloc failed");
	(*stack)->n = (int) atoi(globalVar->tokens[1]);
	(*stack)->next = (*stack)->prev = NULL;
	if (globalVar->temp != NULL)
	{
		(*stack)->next = globalVar->temp;
		globalVar->temp->prev = *stack;
	}
	globalVar->temp = *stack;
	globalVar->stackLen += 1;
}

