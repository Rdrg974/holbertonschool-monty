#ifndef __MONTY__H__
#define __MONTY__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

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
 * struct fclose_s - structure to close a file
 * @file: file
 * @tmp: strdup buffer
 * @opcode: a command
 *
 * Description: a structure meant
 * to close a file
 */
typedef struct fclose_s
{
	FILE *file;
	char *tmp;
	char *opcode;
} fclose_t;

extern fclose_t _close;

void tokenize(stack_t **stack, instruction_t instructions[],
		int line_number, char *line, FILE *file);
int convert_if_int(stack_t **stack, char *tmp,
		char *second_argument, int number, FILE *file);
void free_stack(stack_t *stack);
void get_opcode(stack_t **stack, instruction_t instruction[], FILE *file);
void push(stack_t **stack, unsigned int number);
void pall(stack_t **stack, unsigned int number);
void pint(stack_t **stack, unsigned int number);
void pop(stack_t **stack, unsigned int number);
void nop(stack_t **stack, unsigned int number);
void swap(stack_t **stack, unsigned int number);
void add(stack_t **stack, unsigned int number);

#endif
