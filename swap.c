#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 *
 * @stk: pointer to the pointer to the stack
 * @ln_num: line number in the Monty script where 'swap' was called
 */

void swap(stack_t **stk, unsigned int ln_num)
{
	stack_t *top1;
	stack_t *top2;
	int temp;

	if (!stk || !(*stk) || !(*stk)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln_num);
		exit(EXIT_FAILURE);
	}

	top1 = *stk;
	top2 = top1->next;

	temp = top1->n;
	top1->n = top2->n;
	top2->n = temp;
}
