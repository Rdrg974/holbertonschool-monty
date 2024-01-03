#include "monty.h"

/**
 * tokenize - function who tokenize a string
 * @line: a string of character
 * @line_number: a number of the line
 * Return: an array of string of character
 */

char **tokenize(char *line, int line_number)
{
	int i = 0;
	char *token;
	char **tab = malloc(sizeof(char *) * 2);

	if (tab == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		if (i >= 2)
		{
			fprintf(stderr, "L%d: unknown instruction <opcode>\n", line_number);
			exit(EXIT_FAILURE);
		}
		tab[i] = malloc(strlen(token) + 1);
		if (tab[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(tab[i], token);
		i++;
		token = strtok(NULL, " \t\n");
	}
	return (tab);
}

/**
 * get_opcode - get the function corresponding to opcode
 * @stack: stack to fill
 * @instructions: opcode and its function
 * @file: file to read
 */

void get_opcode(stack_t *stack, instruction_t instructions[], FILE *file)
{
	int i = 0, number = 0, line_number = 1;
	char **tab = NULL, line[1024];

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
		free_tab(tab);
		line_number++;
	}
}

void free_tab(char **tab)
{
	int i = 0;

	if (tab == NULL)
		return;
	for (i = 0; tab[i] != NULL; i++)
		free(tab[i]);
	free(tab);
}
