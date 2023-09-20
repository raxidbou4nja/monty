#include "monty.h"

/**
 * execute_opcode - execute the specified opcode with its argument.
 *
 * @opcode: opcode to execute.
 * @arg: argument associated with the opcode (if any).
 * @stk: pointer to the pointer to the stack.
 * @file: target file
 * @line: command line
 * @line_number: line number in the Monty
 * script where the opcode was encountered.
 *
 * Return: 1 or 0
 */

int execute_opcode(char *opcode, char *arg,
	stack_t **stk, unsigned int line_number, FILE *file, char *line)
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
		push(stk, atoi(arg));
	}
	else if (strcmp(opcode, "pint") == 0)
		pint(stk, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stk, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stk, line_number);
	else if (strcmp(opcode, "pall") == 0)
		pall(stk);
	else if (strcmp(opcode, "add") == 0)
		add(stk, line_number);
    else if (strcmp(opcode, "sub") == 0)
        sub(stk, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(stk, line_number);
	else
		return (0);

	return (1);
}


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
	FILE *file = fopen(argv[1], "r");
	stack_t *stk = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		char *opcode = strtok(line, " \n");
		char *arg = strtok(NULL, " \n");

		line_number++;

		if (opcode)
		{
			if (!execute_opcode(opcode, arg, &stk, line_number, file, line))
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				free(line);
				fclose(file);
				return (EXIT_FAILURE);
			}
		}
	}

	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}

