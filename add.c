#include "monty.h"

/**
 * add - add the top two elements of the stack
 * @stack: stack containing elements
 * @line_number: line number
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int sum = 0;

	if (*stack == NULL || ((*stack)->prev == NULL && (*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	sum = tmp->n + tmp->next->n;
	tmp->next->n = sum;
	*stack = tmp->next;
	free(tmp);
}
