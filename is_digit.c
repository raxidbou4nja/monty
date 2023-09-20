#include "monty.h"

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
