#include "monty.h"

/**
 * free_globalVar - frees dynamically allocated memory
 * in struct it points to
 *
 * Return: no return value
 */
void free_globalVar(void)
{
	if (globalVar == NULL)
		return;
	if (globalVar->instructPtr)
	{
		free(globalVar->instructPtr);
		globalVar->instructPtr = NULL;
	}
	free_temp();
	if (globalVar->line)
	{
		free(globalVar->line);
		globalVar->line = NULL;
	}
	free(globalVar);
}

/**
 * free_temp - frees temporary pointer
 *
 * Return: no return value
 */
void free_temp(void)
{
	if (globalVar->temp)
		free_stack(globalVar->temp);
	globalVar->temp = NULL;
}

/**
 * free_stack - frees stack
 * @temp: points to the head of the stack
 * Return: no return value
 */
void free_stack(stack_t *temp)
{
	if (temp == NULL)
		return;
	if (temp->next != NULL)
	{
		free_stack(temp->next);
	}
	free(temp);
}

/**
 * free_token_array - frees up the space allocated for
 * array of tokens
 *
 * Return: no return value
 */
void free_token_array(void)
{
	int i;

	if (globalVar->tokens == NULL)
		return;
	for (i = 0; globalVar->tokens[i] != NULL; i++)
		free(globalVar->tokens[i]);
	free(globalVar->tokens);
	globalVar->tokens = NULL;
}

/**
 * free_instructPtr - frees instruction pointer only
 *
 * Return: no return value
 */
void free_instructPtr(void)
{
	if (globalVar->instructPtr)
	{
		free(globalVar->instructPtr);
		globalVar->instructPtr = NULL;
	}
}
