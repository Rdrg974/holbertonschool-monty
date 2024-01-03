#include "monty.h"

/**
 * pall_function - prints all the values on the stack
 * @stack: stack to fill
 * @number: line number
 */

void pall_function(stack_t **stack, unsigned int number)
{
	(void) number;
	stack_t *node;

	if (stack == NULL)
		return;
	node = *stack;
	while (node != NULL)
	{
		fprintf(stdout, "%d\n", node->n);
		node = node->next;
	}
}
