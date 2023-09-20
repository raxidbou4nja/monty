#include "monty.h"

/**
 * monty_div - divides the second top element of the stack by the top element
 *
 * @stk: pointer to the pointer to the stack
 * @ln_num: line number in the Monty script where 'div' was called
 *
 */

void monty_div(stack_t **stk, unsigned int ln_num)
{
	stack_t *top1;
	stack_t *top2;

	if (!stk || !(*stk) || !(*stk)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", ln_num);
		exit(EXIT_FAILURE);
	}

	top1 = *stk;
	top2 = top1->next;

	if (top1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln_num);
		exit(EXIT_FAILURE);
	}

	top2->n /= top1->n;

	*stk = top2;
	top2->prev = NULL;

	free(top1);
}

/**
 * mul - multiplies the second top element of the stack with the top element
 * @stk: Pointer to the top of the stack
 * @ln_num: Line number of the opcode
 */

void mul(stack_t **stk, unsigned int ln_num)
{
	if (*stk == NULL || (*stk)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln_num);
		exit(EXIT_FAILURE);
	}

	(*stk)->next->n *= (*stk)->n;
	pop(stk, ln_num);
}

/**
 * sub - subtracts the top element of the stack from the second top element.
 *
 * @stk: pointer to the pointer to the stack.
 * @ln_num: line number in the Monty script where 'sub' was called.
 *
 */

void sub(stack_t **stk, unsigned int ln_num)
{
	stack_t *top1;
	stack_t *top2;

	if (!stk || !(*stk) || !(*stk)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln_num);
		exit(EXIT_FAILURE);
	}

	top1 = *stk;
	top2 = top1->next;

	top2->n -= top1->n;

	*stk = top2;
	top2->prev = NULL;

	free(top1);
}
