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
			fprintf(stderr, "L%d: unknown instruction <opcode>", line_number);
			exit(EXIT_FAILURE);
		}
		tab[i] = token;
		token = strtok(NULL, " \t");
		i++;
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
	int i = 0, line_number = 1;
	int file, bytes_read, number;
	char **tab, line[1024];
	const char *file_from;
	stack_t **stack;
	instruction_t instruction[] = {
		{"push", push_function},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_from = argv[1];
	file = open(file_from, O_RDONLY);
	if (file == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_from);
		exit(EXIT_FAILURE);
	}
	while ((bytes_read = read(file, line, 1024)) > 0)
	{
		tab = tokenize(line, line_number);
		while (instruction[i].opcode != NULL)
		{
			if (strcmp(instruction[i].opcode, "push") == 0)
		{
			number = convert_if_int(tab[1], line_number);
			instruction[i].f(stack, number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction <opcode>", line_number);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	if (bytes_read == -1)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", file_from);
		exit(EXIT_FAILURE);
	}
}
