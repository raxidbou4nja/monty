#include "monty.h"
/**
 * nop - Does nothing.
 *
 * @stk: pointer to the pointer to the stack
 * @ln_num: line number in the Monty script where 'nop' was called
 *
 */

void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack; 
    (void)line_number;
}
