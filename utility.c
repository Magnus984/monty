#include "monty.h"

/**
 * is_valid_number - checks if
 * string is a valid integer number
 *
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
