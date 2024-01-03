#include "monty.h"

/**
 * get_opcode - get the function corresponding to opcode
 * @stack: stack to fill
 * @instructions: opcode and its function
 * @file: file to read
 */

void get_opcode(stack_t *stack, instruction_t instructions[], FILE *file)
{
	int i = 0, number = 0, line_number = 1;
	char **tab, line[1024];
	*stack = NULL;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		tab = tokenize(line, line_number);
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(instructions[i].opcode, tab[0]) == 0)
			{
				if (tab[1] != NULL)
					number = convert_if_int(tab[1], line_number);
				instructions[i].f(&stack, number);
				break;
			}
		}
		if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction <opcode>\n", line_number);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
}
