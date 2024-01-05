#include "monty.h"

/**
 * pop - remove element top of the stack
 * @stack: stack containing elements
 * @line_number: number of lines
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(_close.file);
		free(_close.tmp);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	*stack = current->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current);
}
