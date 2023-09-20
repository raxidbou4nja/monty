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