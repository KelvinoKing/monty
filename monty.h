#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

extern int global_variable;
int global_variable;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *check_word(char *line, stack_t **head, int num_lines);
void get_instructions(char *word, stack_t **head, unsigned int line_num);
void push(stack_t **head, unsigned int line_num);
void display(stack_t **head, unsigned int line_num);
void my_free(stack_t *head);
int len_stack(stack_t *head);
void swap(stack_t **head, unsigned int line_num);
void pop(stack_t **head, unsigned int line_num);
void add(stack_t **head, unsigned int line_num);
void nop(stack_t **head, unsigned int line_num);
void sub(stack_t **head, unsigned int line_num);
void div_func(stack_t **head, unsigned int line_num);
void mul_func(stack_t **head, unsigned int line_num);
void mod_func(stack_t **head, unsigned int line_num);
#endif /*MONTY_H*/
