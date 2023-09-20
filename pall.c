#include "monty.h"

/**
 * pall - prints all the values on the stack
 *
 * @stk: pointer to the pointer to the stack
 *
 */

void pall(stack_t **stk)
{
	stack_t *current = *stk;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
