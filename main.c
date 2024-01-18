#include "monty.h"

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
