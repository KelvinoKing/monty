#include "monty.h"

/**
 * push - adds an element in the stack
 * @head: pointer to pointer of head node
 * @line_num: line number
 *
 * Return: void
 */
void push(stack_t **head, unsigned int line_num)
{
	stack_t *new;

	(void) line_num;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->n = global_variable;
	new->prev = NULL;

	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
		return;
	}
	else
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
}

/**
 * display - diaplays all elements in stack
 * @head: pointer to pointer of head node
 * @line_num: line number
 *
 * Return: void
 */
void display(stack_t **head, unsigned int line_num)
{
	stack_t *ptr;

	(void) line_num;
	ptr = *head;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * get_instructions - calls the specified function
 * @word: command
 * @head: pointer to pointer of head node
 * @line_num: line number
 *
 * Return: void
 */
void get_instructions(char *word, stack_t **head, unsigned int line_num)
{
	instruction_t array[] = {
		{"push", push},
		{"pall", display},
		{NULL, NULL}
	};
	int i = 0;

	while (array[i].opcode != NULL)
	{
		if (strcmp(array[i].opcode, word) == 0)
		{
			array[i].f(head, line_num);
			return;
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", line_num, word);
	exit(EXIT_FAILURE);
}
