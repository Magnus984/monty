#include "monty.h"

/**
 * get_stream - gets file stream
 * @file_name: name of file to open
 *
 * Return: no return value
 */
void get_stream(char *file_name)
{

	globalVar->stream = fopen(file_name, "r");
	if (globalVar->stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
}

/**
 * close_stream - closes file stream
 *
 * Return: no return value
 */
void close_stream(void)
{
	if (!(globalVar->stream))
	{
		fclose(globalVar->stream);
		globalVar->stream = NULL;
	}
}
