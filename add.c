#include "monty.h"
/**
 * add - adds the top two elements of the stack
 *
 * @stk: pointer to the pointer to the stack
 * @ln_num: line number in the Monty script where 'add' was called
 */

void add(stack_t **stk, unsigned int ln_num)
{
    stack_t *top1;
    stack_t *top2;

	if (!stk || !(*stk) || !(*stk)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln_num);
		exit(EXIT_FAILURE);
	}

	top1 = *stk;
	top2 = top1->next;

	top2->n += top1->n;

	*stk = top2;
	top2->prev = NULL;

	free(top1);
}
