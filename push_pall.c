#include "monty.h"

/**
 * push- pushes element into a stack
 * @stack: pointer to the top of the stack
 * @line_number: number line where the push operation is peeformed
 * Return: Nothing
*/

void push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *new_node;
	char *argument_str = strtok(NULL, " ");

	if (argument_str == NULL)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(argument_str);
	if (value == 0 && strcmp(argument_str, "0") != 0)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack == NULL)
	{
		*stack = new_node;
		top = *stack;
	}
	else
	{
		new_node->prev = top;
		top->next = new_node;
		top = new_node;
	}
}
/**
 * pall - prints elements of the stack
 * @stack: pointer to top of the stack
 * @line_number: number line where the pall operation is performed
 * Return: Nothing
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
/**
 * readFile - function that reads a file
 * @filename: name of the file
 * Return : nothing
*/
void readFile(const char *filename)
{
	char line[100];
	unsigned int line_number = 1;
	char *opcode;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file))
	{
		line[strcspn(line, "\n")] = '\0';
		opcode = strtok(line, " ");

		if (strcmp(opcode, "push") == 0)
		{
			push(&top, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&top, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: Unknown instruction %s\n", line_number, opcode);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	fclose(file);
}
/**
 * main - entry point
 * @argc: no. of cmd arguments
 * @argv: array of cmd arguments
 * Return: 0 on  success
*/

int main(int argc, char *argv[])
{
	char *filename;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	filename = argv[1];
	readFile(filename);

	return (EXIT_SUCCESS);
}
