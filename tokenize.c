#include "monty.h"

int tokenNumber = 0;
char **tokens = NULL;
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
	/*get the number of tokens*/
	copy_of_line = strdup(line);
	if (copy_of_line == NULL)
		fprintf(stderr, "string duplication failed");
	token = strtok(copy_of_line, " \n");
	while (token != NULL)
	{
		tokenNumber++;
		token = strtok(NULL, " \n");
	}
	/*assigning tokens to token array*/
	tokens = malloc(sizeof(char *) *(tokenNumber + 1));
	if (tokens == NULL)
		fprintf(stderr, "malloc fialed");
	copy_of_line = strdup(line);
	token = strtok(copy_of_line, " \n");
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		if (tokens[i] == NULL)
			fprintf(stderr, "string duplication failed");
		token = strtok(NULL, " \n");
		i++;
	}
	tokens[i] = NULL;
	free(copy_of_line);
}
