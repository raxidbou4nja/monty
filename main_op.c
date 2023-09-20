#include "monty.h"

/**
 * push - pushes an integer onto the stack
 *
 * @stk: pointer to the pointer to the stack
 * @num: integer to be pushed onto the stack
 *
 */

void push(stack_t **stk, int num)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stk;

	if (*stk)
	{
		(*stk)->prev = new_node;
	}

	*stk = new_node;
}

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
