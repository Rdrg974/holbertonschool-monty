#include "monty.h"

/**
 * convert_if_int - convert char to int
 * @arg2: string to convert to int
 * @line_number: line number
 * 
 * Return: number
 */

int convert_if_int(char *arg2, line_number)
{
	int i = 0;
	while (arg2[i] != '\0')
	{
		if (isdigit(arg2[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	number = atoi(arg2);
	return (number);
}

/**
 * push_function - add elements to stack
 * @number: number to add
 */
void push_function(number) 
{
	instruction_t push;
	stack_t stack_push;
	push.opcode = "push";
	push.handle_opcode(stack_push, number);
}

/**
 * handle_opcode - create a doubly-linked list of elements
 * @stack: stack to fill
 * @line_number: line number
 */

void *handle_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = line_number;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
