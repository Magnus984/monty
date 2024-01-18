#include "monty.h"

/**
 * print_tokens - prints tokens in the token array,
 * this is a test file
 *
 * Return: no return value
 */
void print_tokens(void)
{
	int i = 0;
	while (tokens[i] != NULL)
	{
		printf("%s\n", tokens[i]);
		i++;
	}
}
