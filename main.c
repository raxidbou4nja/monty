#include "monty.h"

/**
 * main - entry point for the Monty bytecode interpreter
 *
 * @argc: number of command-line arguments
 * @argv: array of strings containing the command-line arguments
 *
 * Return:
 * - EXIT_SUCCESS if successfully executes the Monty script
 * - EXIT_FAILURE if any error occurs during interpretation
 */


int main(int argc, char *argv[])
{
	stack_t *stk = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	FILE *file = fopen(argv[1], "r");
	unsigned int line_number = 0;
	char *opcode, *arg;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;

		opcode = strtok(line, " \n");
		arg = strtok(NULL, " \n");

		if (opcode)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (!arg || !is_integer(arg))
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					free(line);
					fclose(file);
					exit(EXIT_FAILURE);
				}
				push(&stk, atoi(arg));
			}
			else if (strcmp(opcode, "pint") == 0)
			{
				pint(&stk, line_number);
			}
			else if (strcmp(opcode, "pop") == 0)
			{
				pop(&stk, line_number);
			}
			else if (strcmp(opcode, "swap") == 0)
			{
				swap(&stk, line_number);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(&stk);
			}
			else if (strcmp(opcode, "add") == 0)
			{
				add(&stk, line_number);
			}
			else if (strcmp(opcode, "nop") == 0)
			{
				nop(&stk, line_number);
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				free(line);
				fclose(file);
				exit(EXIT_FAILURE);
			}
		}
	}

	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}
