#include"monty.h"
/**
 * find_integer - Checks if the given string is a valid integer.
 * @line_number: The line number where the integer is being checked.
 * @args: The string .
 * Return: Nothing(void).
 */
int find_integer(unsigned int line_number, char *args)
{
	if (args == NULL || *args == '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (*args == '-' || *args == '+')
		args++;

	while (*args != '\0')
	{
		if (!isdigit(*args))
		{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
		}
		args++;
	}
	return (1);
}

/**
 * find_opcode - Checks if the token matches any opcode
 * @token: the t0ken thats beng checked
 * @op_codes_funcs: the array
 * @line_number: line number wher the operstion is performed
 * @working_stack: func parameter
 * Return: 0 on success
*/
int find_opcode(const char *token,
instruction_t *op_codes_funcs,
stack_t **working_stack, unsigned int line_number)
{
	int i = 0;

	while (op_codes_funcs[i].opcode != NULL)
	{
		if (strcmp(token, op_codes_funcs[i].opcode) == 0)
		{
			if (strcmp(token, "push") == 0)
			{
				char *args = strtok(NULL, " \t\n");

				if (args == NULL)
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}

				find_integer(line_number, args);

				op_codes_funcs[i].f(working_stack, atoi(args));
			}
			else
			{
				op_codes_funcs[i].f(working_stack, line_number);
			}
			return (1);
		}
		i++;
	}
	return (0);
}
