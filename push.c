#include "monty.h"

/**
 * convert_if_int - convert char to int
 * @stack: stack to fill
 * @tmp: variable tmp
 * @arg2: string to convert to int
 * @line_number: line number
 * @file: file contains commands
 * Return: number
 */

int convert_if_int(stack_t **stack, char *tmp,
		char *arg2, int line_number, FILE *file)
{
	int i = 0, number = 0;

	while (arg2[i] != '\0')
	{
		if (arg2[i] == '-')
			i++;
		if (isdigit(arg2[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(tmp), free_stack(*stack), fclose(file);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	number = atoi(arg2);
	return (number);
}

/**
 * push - add elements to stack
 * @stack: stack to fill
 * @number: argument of push
 */

void push(stack_t **stack, unsigned int number)
{
	stack_t *new_node = malloc(sizeof(stack_t) * 1);

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = number;
	new_node->next = *stack;
	if ((*stack) != NULL)
		(*stack)->prev = new_node;
	new_node->prev = NULL;
	(*stack) = new_node;
}

/**
 * free_stack - free the stack
 * @stack: stack containting elements to free
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
