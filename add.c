#include "monty.h"

/**
 * add - add the top two elements of the stack
 * @stack: stack containing elements
 * @line_number: line number
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1;
	int sum = 0;

	if (*stack == NULL || ((*stack)->prev == NULL && (*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		fclose(_close.file);
		free(_close.tmp);
		exit(EXIT_FAILURE);
	}
	tmp1 = *stack;
	sum = tmp1->n + tmp1->next->n;
	tmp1->next->n = sum;
	*stack = tmp1->next;
	free(tmp1);
}
