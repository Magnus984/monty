#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*Standard libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * struct var_s - variables declared in struct to make them global
 * @stream: file stream from which reading takes place
 * @line: string of read
 * @lineNumber: linenumber read in file
 * @tokens: array of strings containing tokens from a line
 * @tokenNumber: number of tokens in token array
 * @instructPtr: storing opcode and function address temporary
 * @temp: temporary mem location
 * @stackLen: length of stack
 *
 * Description: these variables are for the various functions
 */
typedef struct var_s
{
	FILE *stream;
	char *line;
	int lineNumber;
	char **tokens;
	int tokenNumber;
	instruction_t *instructPtr;
	stack_t *temp;
	int stackLen;
} var_t;

extern var_t *globalVar;

/*function prototypes*/
void get_stream(char *file_name);
void print_tokens(void);
void tokenize(void);
void get_instruction(void);
void execute_instruction(void);
void init_args(void);
void close_stream(void);

/*free function prototypes*/
void free_token_array(void);
void free_temp(void);
void free_globalVar(void);
void free_stack(stack_t *temp);
void free_instructPtr(void);

/*utility function prototypes*/
int is_valid_number(char *str);
void free_line(void);

/*opcodes*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

#endif /*MONTY_H*/
