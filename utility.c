#include "monty.h"

/**
 * is_valid_number - checks if
 * string is a valid integer number
 * @str: second token
 * Return: 1 if valid, 0 otherwise
 */
int is_valid_number(char *str)
{
	int i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i > 0 && str[i] == '\0')
		return (1);
	return (0);
}

/**
 * free_line - frees line after each read
 * from getline
 *
 * Return: no return value
 */
void free_line(void)
{
	if (globalVar->line)
	{
		free(globalVar->line);
		globalVar->line = NULL;
	}
}
