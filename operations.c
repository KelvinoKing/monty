#include "monty.h"

/**
 * sub - Subracts top element from the second in the stack
 * @head: pointer to pointer of head node
 * @line_num: the number of line with error
 */
void sub(stack_t **head, unsigned int line_num)
{
	int diff;
	stack_t *temp;

	temp = *head;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	diff = temp->next->n - temp->n;
	(*head)->next->n = diff;
	pop(head, line_num);
}
