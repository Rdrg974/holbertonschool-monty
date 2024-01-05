#include "monty.h"

/**
 * tokenize - function who tokenize a string
 * @stack: stack to fill
 * @instructions: opcode and its function
 * @line_number: a number of the line
 * @line: a string of character
 * @file: file
 */

void tokenize(stack_t **stack, instruction_t instructions[],
		int line_number, char *line, FILE *file)
{
	int i = 0, number = 0;
	char *token, *tmp;

	tmp = strdup(line);
	if (tmp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	token = strtok(tmp, " \t\n");
	_close.tmp = tmp;
	_close.opcode = token;
	while (token != NULL && instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, token) == 0)
		{
			if (strcmp(token, "push") == 0)
			{
				token = strtok(NULL, " \t\n");
				if (token == NULL)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					free(tmp), free_stack(*stack), fclose(file), exit(EXIT_FAILURE);
				}
				number = convert_if_int(stack, tmp, token, line_number, file);
				instructions[i].f(stack, number);
			}
			else
				instructions[i].f(stack, line_number);
			break;
		}
		i++;
	}
	if (instructions[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, _close.opcode);
		free(tmp), free_stack(*stack), fclose(file), exit(EXIT_FAILURE);
	}
	free(tmp);
}

/**
 * get_opcode - get the function corresponding to opcode
 * @stack: stack to fill
 * @instructions: opcode and its function
 * @file: file to read
 */

void get_opcode(stack_t **stack, instruction_t instructions[], FILE *file)
{
	int line_number = 1;
	char line[1024], *tmp1, *tmp2;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		tmp1 = strdup(line);
		if (tmp1 == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_stack(*stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		tmp2 = strtok(tmp1, " \t\n");
		if (tmp2 == NULL)
		{
			free(tmp1);
			line_number++;
			continue;
		}
		free(tmp1);
		tokenize(stack, instructions, line_number, line, file);
		line_number++;
	}
}
