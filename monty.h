#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>


typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *stk;

void push(stack_t **stk, int num);
void pall(stack_t **stk);
void pint(stack_t **stk, unsigned int ln_num);
void pop(stack_t **stk, unsigned int ln_num);
void swap(stack_t **stk, unsigned int ln_num);
void add(stack_t **stk, unsigned int ln_num);
void nop(stack_t **stk, unsigned int ln_num);
void sub(stack_t **stk, unsigned int ln_num);

int is_integer(const char *string);

#endif
