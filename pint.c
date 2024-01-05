#include "monty.h"

/**
 * pint - print element at the top of the stack
 * @stack: stack containing elements
 * @line_number: number of line
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(_close.file);
		free(_close.tmp);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	fprintf(stdout, "%d\n", node->n);
}
