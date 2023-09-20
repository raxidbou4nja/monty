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
