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
	free_stack(stk);
	return (EXIT_SUCCESS);
}
