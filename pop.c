#include "monty.h"

/**
 * pop - remove element top of the stack
 * @stack: stack containing elements
 * @number: number of lines
 */

void pop(stack_t **stack, unsigned int number)
{
	(void) number;
	stack_t *current = *stack;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", number);
		exit(EXIT_FAILURE);
	}
	*stack = current->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current);
}
