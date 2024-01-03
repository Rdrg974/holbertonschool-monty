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
	char **tab = malloc(1024);

	if (tab == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t");
	while (token != NULL)
	{
		if (i > 1)
		{
			fprintf(stderr, "L%d: unknown instruction <opcode>\n", line_number);
			exit(EXIT_FAILURE);
		}
		tab[i] = token;
		i++;
		token = strtok(NULL, " \t");
	}
	return (tab);
}

/**
 * main - a programm who implement the push and pall opcodes
 * @argc: the number of argument
 * @argv: the arguments
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	FILE *file;
	int i, line_number = 1, number;
	char **tab, line[1024];
	const char *file_from;
	stack_t **stack = NULL;
	instruction_t instruction[] = {{"push", push_function},
		{"pall", pall_function}, {NULL, NULL}};

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file_from = argv[1];
	file = fopen(file_from, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_from);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		tab = tokenize(line, line_number);
		for (i = 0; instruction[i].opcode != NULL; i++)
		{
			if (strcmp(instruction[i].opcode, tab[0]) == 0)
			{
				number = convert_if_int(tab[1], line_number);
				instruction[i].f(stack, number);
				break;
			}
		}
		if (instruction[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction <opcode>\n", line_number);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	fclose(file);
	return (0);
}
