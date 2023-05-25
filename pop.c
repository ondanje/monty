#include"monty.h"
/**
 * pop-removes the top element of the stack.
 * @stack: pointer to pointer to the top of the stack
 * @line_number: lone number where the operation will be carried out
 * Return : nothing
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;


	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
