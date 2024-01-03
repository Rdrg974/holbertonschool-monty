#include "monty.h"



void pall_function(stack_t **stack, unsigned int number)
{
	(void) number;

	while (stack != NULL)
	{
		fprintf(stdout, "%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}
