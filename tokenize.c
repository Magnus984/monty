#include "monty.h"

/**
 * tokenize - tokenizes line and stores each token
 *
 * Return: no return value
 */
void tokenize(void)
{
	char *copy_of_line;
	int i = 0;
	char *token = NULL;

	copy_of_line = strdup(globalVar->line);
	if (copy_of_line == NULL)
		fprintf(stderr, "string duplication failed");
	globalVar->tokenNumber = 0;
	token = strtok(copy_of_line, " \t$\n");
	while (token != NULL)
	{
		globalVar->tokenNumber += 1;
		token = strtok(NULL, " \t$\n");
	}
	free(copy_of_line);
	copy_of_line = NULL;
	globalVar->tokens = malloc(sizeof(char *)
			* (globalVar->tokenNumber + 1));
	if (globalVar->tokens == NULL)
		fprintf(stderr, "malloc fialed");
	copy_of_line = strdup(globalVar->line);
	token = strtok(copy_of_line, " \t$\n");
	while (token != NULL)
	{
		globalVar->tokens[i] = strdup(token);
		if (globalVar->tokens[i] == NULL)
			fprintf(stderr, "string duplication failed");
		token = strtok(NULL, " \t$\n");
		i++;
	}
	globalVar->tokens[i] = NULL;
	free(copy_of_line);
}
