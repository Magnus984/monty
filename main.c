#include "monty.h"

var_t *globalVar = NULL;
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
	init_args();
	get_stream(argv[1]);
	read = getline(&globalVar->line, &n, globalVar->stream);
	while (read != -1)
	{
		globalVar->lineNumber += 1;
		tokenize();
		/*print_tokens();*/
		get_instruction();
		execute_instruction();
		free_token_array();
		read = getline(&globalVar->line, &n, globalVar->stream);
	}
	close_stream();
	free_globalVar();
	return (0);

}
