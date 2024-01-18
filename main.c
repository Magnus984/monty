#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *line = NULL;
int lineNumber = 0;
/**
 * main - entry point of program
 * @argc: argument count
 * @argv: array of argument as strings
 *
 * Return: no return value
 */
int main(int argc, char **argv)
{
	ssize_t read;

	size_t n = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	get_stream(argv[1]);
	read = getline(&line, &n, stream);
	while (read != -1)
	{
		lineNumber++;
		tokenize();
		print_tokens();
		read = getline(&line, &n, stream);
	}
	free(line);
	fclose(stream);
	return (0);

}
/**
 * error_usage - This will print usage message and exit
 *
 * Return: nothing
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * file_error - This will print file error message and exit
 * @argv: argv given by the  manin
 *
 * Return: nothing
 */

void file_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

