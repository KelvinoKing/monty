#include "monty.h"

/**
 * free_stack - free a memory stack
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
