#include "monty.h"

/**
 * init_args - initializes pointer globalVar
 * of type var_s
 *
 * Return: no return value
 */
void init_args(void)
{
	globalVar = malloc(sizeof(var_t));
	if (globalVar == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	globalVar->instructPtr = malloc(sizeof(instruction_t));
	if (!globalVar->instructPtr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	globalVar->line = NULL;
	globalVar->tokens = NULL;
	globalVar->lineNumber = 0;
	globalVar->tokenNumber = 0;
	globalVar->stackLen = 0;
	globalVar->stream = NULL;
}
      	       
