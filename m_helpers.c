#include "monty.h"

/**
 * free_stack - Frees the entire stack and all its nodes
 * @stk: Pointer to the top of the stack
 */

void free_stack(stack_t *stk)
{
	stack_t *current = stk;

	while (current != NULL)
	{
		stack_t *temp = current;

		current = current->next;
		free(temp);
	}
}

/**
 * is_integer - checks if a string represents a valid integer
 *
 * @string: input string to be checked
 *
 * Return:
 * - 1 represents a valid integer
 * - 0 doens't represent a valid integer
 */

int is_integer(const char *string)
{
	int idx;

	if (!string)
		return (0);

	idx = 0;

	if (string[idx] == '-')
		idx++;

	for (; string[idx] != '\0'; idx++)
	{
		if (!isdigit(string[idx]))
			return (0);
	}

	return (1);
}

/**
 * execute_opcode - execute the specified opcode with its argument.
 *
 * @opcode: opcode to execute.
 * @arg: argument associated with the opcode (if any).
 * @stk: pointer to the pointer to the stack.
 * @file: target file
 * @line: command line
 * @line_number: line number in the Monty
 * script where the opcode was encountered.
 *
 * Return: 1 or 0
 */

int execute_opcode(char *opcode, char *arg,
	stack_t **stk, unsigned int line_number, FILE *file, char *line)
{
	if (strcmp(opcode, "push") == 0)
	{
		if (!arg || !is_integer(arg))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		push(stk, atoi(arg));
	}
	else if (strcmp(opcode, "pint") == 0)
		pint(stk, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stk, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stk, line_number);
	else if (strcmp(opcode, "pall") == 0)
		pall(stk);
	else if (strcmp(opcode, "add") == 0)
		add(stk, line_number);
	else if (strcmp(opcode, "div") == 0)
		monty_div(stk, line_number);
	else if (strcmp(opcode, "sub") == 0)
		sub(stk, line_number);
	else if (strcmp(opcode, "mul") == 0)
		mul(stk, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(stk, line_number);
	else
		return (0);

	return (1);
}
