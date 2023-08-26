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
		fprintf(stderr, "Error: malloc failed");
		my_free(*head);
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
 * pall - diaplays all elements in stack
 * @head: pointer to pointer of head node
 * @line_num: line number
 *
 * Return: void
 */
void pall(stack_t **head, unsigned int line_num)
{
	stack_t *ptr;

	(void) line_num;
	ptr = *head;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * pint - Prints out the top element of stack
 * @head: pointer to pointer of head node
 * @line_num: line number
 */
void pint(stack_t **head, unsigned int line_num)
{
	stack_t *temp = NULL;

	temp = *head;
	if (temp == NULL || head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		my_free(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", temp->n);
	}

}

/**
 * pop - Removes the top element of the stack
 * @head: pointer to pointer of head node
 * @line_num: line number
 *
 * Return: void
 */
void pop(stack_t **head, unsigned int line_num)
{
	stack_t *temp;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(temp);
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
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_func},
		{"mul", mul_func},
		{"mod", mod_func},
		{NULL, NULL}
	};
	int i = 0;

	while (array[i].opcode != NULL)
	{
		if (word[0] == '#')
			return;
		else if (strcmp(array[i].opcode, word) == 0)
		{
			array[i].f(head, line_num);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, word);
	my_free(*head);
	exit(EXIT_FAILURE);
}
