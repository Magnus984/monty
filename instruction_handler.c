#include "monty.h"

/**
 * get_instruction - matches opcode to opcode function
 *
 * Return: no return value
 */
void get_instruction(void)
{
	int i;

	instruction_t instructionArray[] = {
		{"pall", &pall}, {"push", &push},
		{"pint", &pint}, {"pop", &pop},
		{NULL, NULL}};
	if (globalVar->tokenNumber == 0)
		return;
	i = 0;
	globalVar->instructPtr = malloc(sizeof(instruction_t));
	while (instructionArray[i].opcode != NULL)
	{
		if (strcmp(instructionArray[i].opcode, globalVar->tokens[0]) == 0)
		{
			globalVar->instructPtr->opcode = instructionArray[i].opcode;
			globalVar->instructPtr->f = instructionArray[i].f;
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unkown instruction %s\n",
			globalVar->lineNumber, globalVar->tokens[0]);
	close_stream();
	free_token_array();
	free_globalVar();
	exit(EXIT_FAILURE);
}

/**
 * execute_instruction - executes instruction
 *
 * Return: no return value
 */
void execute_instruction(void)
{
	stack_t *stack = NULL;

	if (globalVar->tokenNumber != 0)
		globalVar->instructPtr->f(&stack, globalVar->lineNumber);
}
