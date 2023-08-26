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

/**
 * div - Divides second element by top element of stack
 * @head: pointer to pointer of head node
 * @line_num: line number with error
 */
void div_func(stack_t **head, unsigned int line_num)
{
	stack_t *temp;
	int result;

	temp = *head;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	result = temp->next->n / temp->n;
	(*head)->next->n = result;
	pop(head, line_num);
}
