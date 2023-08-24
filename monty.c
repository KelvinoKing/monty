#include "monty.h"

/**
 * my_free - frees memory
 * @head_node: pointer to head node
 *
 * Return: void
 */
void my_free(stack_t *head_node)
{
	stack_t *ptr;

	while (head_node != NULL)
	{
		temp = head_node->next;
		free(head_node);
		head_node = temp;
	}
}

/**
 * main - Entry point
 * @argc: number of arguments passed
 * @argv: array of arguments
 *
 * Return: int
 */
int main(int argc, char *argv[])
{
	FILE *file;
	int num_lines = 0;
	size_t line_len = 0;
	char *line = NULL;
	char *word;
	stack_t *head_node;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		file = fopen(argv[1], "r");
		if (file == NULL)
		{
			printf("Error: Can't open file %s", argv[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			while (getline(&line, &line_len, file) != -1)
			{
				num_lines++;
				word = check_word(line, num_lines);
				if (word != NULL)
					get_instructions(word, &head_node, num_lines);
			}
		}
		free(line);
		my_free(head_node);
		fclose(file);
	}

	return (0);
}
