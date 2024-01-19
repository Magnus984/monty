#ifndef MONTY_H
#define MONTY_H

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


/**
 * struct help - argument for the current opcode
 * @data_struct: stack mode, stack (default) and queue
 * @argument: the arguments of the string
 *
 * Description: global structure used to pass data around the functions easily
 */


/*Standard libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * struct globalvar_s - variables declared in struct
 * to make them global
 * @stream: file stream from which reading takes place
 * @line: string of read
 * @lineNumber: linenumber read in file
 * @tokens: array of strings containing tokens from a line
 * @tokenNumber: number of tokens in token array
 * @instructPtr: storing opcode and function address temporary
 * @temp: temporary mem location
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
void get_instruction (void);
void execute_instruction(void);
int is_valid_number(char *str);
void init_args(void);
void close_stream(void);

/*free function prototypes*/
void free_token_array(void);
void free_temp(void);
void free_globalVar(void);
void free_stack(stack_t *temp);

/*opcodes*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);

#endif /*MONTY_H*/
