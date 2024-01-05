#include "monty.h"

/**
 * pall- prints all the values on the stack
 * @stack: stack to fill
 * @line_number: line number
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *node;

	if (*stack == NULL)
		return;
	node = *stack;
	while (node != NULL)
	{
		fprintf(stdout, "%d\n", node->n);
		node = node->next;
	}
}
