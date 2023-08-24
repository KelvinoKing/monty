#include "monty.h"

/**
 * is_numeric - return true if the argument is purely numbers
 * @str: the parameter
 *
 * Return: int
 */
int is_numeric(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * check_word - Checks and separates the line passed into separate words
 * @line: pointer to the line read by getline()
 * @num_lines: line number containing the line
 *
 * Return: pointer to the instruction
 */
char *check_word(char *line, int num_lines)
{
	char *command;
	char *argument;

	command = strtok(line, "\n ");
	if (command == NULL)
		return (NULL);

	argument = strtok(NULL, "\n ");
	if (argument != NULL)
	{
		if (is_numeric(argument))
		{
			global_variable = atoi(argument);
		}
		else
		{
			printf("L%d: usage: push integer\n", num_lines);
			exit(EXIT_FAILURE);
		}
	}
	else if (argument == NULL && strcmp(command, "push") == 0)
	{
		printf("L%d: usage: push integer\n", num_lines);
		exit(EXIT_FAILURE);
	}
	return (command);
}
