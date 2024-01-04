#include "monty.h"

/**
 * pint - print element at the top of the stack
 * @stack: stack containing elements
 * @number: number of line
 */

void pint(stack_t **stack, unsigned int number)
{
	(void) number;
	stack_t *node;

	if (stack == NULL)
		return;
	node = *stack;
	fprintf(stdout, "%d\n", node->n);
}
