#include "monty.h"

/**
 * swap - swap the top two elements of the stack
 * @stack: stack containing elements
 * @line_number: line number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1;
	int new = 0;

	if (*stack == NULL || ((*stack)->prev == NULL && (*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(_close.file);
		free(_close.tmp);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp1 = *stack;
	new = (*stack)->n;
	tmp1->n = (*stack)->next->n;
	(*stack)->next->n = new;
}
