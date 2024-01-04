#include "monty.h"

/**
 * tokenize - function who tokenize a string
 * @stack: stack to fill
 * @instructions: opcode and its function
 * @line_number: a number of the line
 * @line: a string of character
 * Return: stack
 */

stack_t *tokenize(stack_t *stack, instruction_t instructions[],
		int line_number, char *line)
{
	int i = 0, number = 0;
	char *token, *tmp;

	tmp = strdup(line);
	token = strtok(tmp, " \t\n");
	while (token != NULL && instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, token) == 0)
		{
			if (strcmp(token, "push") == 0)
			{
				token = strtok(NULL, " \t\n");
				if (token == NULL)
				{
					free(tmp);
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				number = convert_if_int(token, line_number);
			}
			instructions[i].f(&stack, number);
			free(tmp);
			return (stack);
		}
		i++;
	}
	free(tmp);
	return (NULL);
}

/**
 * get_opcode - get the function corresponding to opcode
 * @stack: stack to fill
 * @instructions: opcode and its function
 * @file: file to read
 */

void get_opcode(stack_t *stack, instruction_t instructions[], FILE *file)
{
	int line_number = 1;
	char line[1024];

	while (fgets(line, sizeof(line), file) != NULL)
	{
		stack = tokenize(stack, instructions, line_number, line);
		if (stack == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction <opcode>\n", line_number);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	free_stack(&stack);
}
