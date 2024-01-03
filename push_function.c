#include "monty.h"

/**
 * convert_if_int - convert char to int
 * @arg2: string to convert to int
 * @line_number: line number
 *
 * Return: number
 */

int convert_if_int(char *arg2, int line_number)
{
	int number = 0;
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
 * @stack: stack to fill
 * @number: line number
 */

void push_function(stack_t **stack, unsigned int number)
{
	stack_t *new_node = malloc(sizeof(stack_t) * 1);

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = number;
	new_node->next = *stack;
	new_node->prev = NULL;

	if ((*stack) != NULL)
		(*stack)->prev = new_node;
	(*stack) = new_node;
	printf("%d\n", (*stack)->n);
}

/*void free_stack(stack_t **stack)
{
	stack_t **tmp;

	while ((*stack) != NULL)
	{
		(*tmp) = (*stack);
		(*stack) = (*stack)->next;
		free(tmp);
	}
}*/
