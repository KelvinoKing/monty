#include "monty.h"

/**
 * my_free - free a memory stack
 * @head: head of a stack
 *
 * Return: void
 */
void my_free(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * nop - does nothing
 * @head: pointer to pointer of head
 * @line_num: number of current line
 */
void nop(stack_t **head, unsigned int line_num)
{
	(void) head;
	(void) line_num;
}
