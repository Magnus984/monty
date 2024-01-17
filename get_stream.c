#include "monty.h"

FILE *stream = NULL;
/**
 * get_stream - gets file stream
 * @file_name: name of file to open
 *
 * Return: no return value
 */
void get_stream(char *file_name)
{

	stream = fopen(file_name, "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
}
