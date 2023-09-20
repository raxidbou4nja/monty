#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 *
 * @stk: pointer to the pointer to the stack
 * @ln_num: line number in the Monty script where 'pint' was called
 */

void pint(stack_t **stk, unsigned int ln_num)
{
	if (!stk || !(*stk))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln_num);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stk)->n);
}
