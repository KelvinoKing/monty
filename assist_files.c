#include "monty.h"

/**
 * len_stack - Returns the size of stack
 * @head: pointer to head node
 *
 * Return: int
 */
int len_stack(stack_t *head)
{
	int count = 0;

	if (head == NULL)
		return (0);
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);

}

/**
 * swap - Swaps two top elements of a stack
 * @head: pointer to pointer of head node
 * @line_num: line number
 *
 * Return: void
 */
void swap(stack_t **head, unsigned int line_num)
{
	stack_t *temp = NULL, *temp2 = NULL;

	temp = *head;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp2 = (*head)->next;

	temp->prev = temp2;
	temp2->prev = NULL;
	temp->next = temp2->next;
	temp2->next = temp;

	*head = temp2;
}

/**
 * add - Adds the first and second element
 * @head: pointer to pointer of head node
 * @line_num: number of line
 */
void add(stack_t **head, unsigned int line_num)
{
	stack_t *temp;
	int sum;

	temp = *head;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	sum = temp->n + temp->next->n;
	(*head)->next->n = sum;
	pop(head, line_num);
}

/**
 * is_numeric - return true if the argument is purely numbers
 * @str: the parameter
 *
 * Return: int
 */
int is_numeric(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

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
 * @head: pointer to head node
 *
 * Return: pointer to the instruction
 */
char *check_word(char *line, stack_t **head, int num_lines)
{
	char *command = NULL;
	char *argument = NULL;
	char delimiter[3] = " \t\n";

	command = strtok(line, delimiter);
	if (command == NULL)
		return (NULL);

	argument = strtok(NULL, delimiter);
	if (argument != NULL)
	{
		if (is_numeric(argument))
		{
			global_variable = atoi(argument);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", num_lines);
			my_free(*head);
			exit(EXIT_FAILURE);
		}
	}
	else if (argument == NULL && strcmp(command, "push") == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", num_lines);
		my_free(*head);
		exit(EXIT_FAILURE);
	}
	return (command);
}
