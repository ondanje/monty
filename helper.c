#include"monty.h"
/**
 * freeup - frees memory
 * @file: file
 * @line: the string
 * @stack: doubly linked list stack
 * Return: nothing(void)
 */
void freeup(FILE *file, char *line, stack_t **stack)
{
	stack_t *current;
	stack_t *next;

	free(line);
	fclose(file);

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
