#include "monty.h"

/**
 * nop - Does nothing.
 *
 * @stk: pointer to the pointer to the stack
 * @ln_num: line number in the Monty script where 'nop' was called
 *
 */

void nop(stack_t **stk, unsigned int ln_num)
{
	(void)stk;
	(void)ln_num;
}

/**
 * pop - removes the top element of the stack
 *
 * @stk: pointer to the pointer to the stack
 * @ln_num: line number in the Monty script where 'pop' was called
 */

void pop(stack_t **stk, unsigned int ln_num)
{
	stack_t *top;

	if (!stk || !(*stk))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln_num);
		exit(EXIT_FAILURE);
	}

	top = *stk;
	*stk = (*stk)->next;

	if (*stk)
	{
		(*stk)->prev = NULL;
	}

	free(top);
}