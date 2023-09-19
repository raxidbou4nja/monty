#include "monty.h"

stack_t *stack = NULL;


int main(int argc, char *argv[])
{
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
                push(&stack, atoi(arg));
            }
            else if (strcmp(opcode, "pall") == 0)
            {
                pall(&stack);
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
    return EXIT_SUCCESS;
}

void push(stack_t **stack, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
    {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

void pall(stack_t **stack)
{
    stack_t *current = *stack;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

int is_integer(const char *str)
{
    int i;

    if (!str)
        return (0);

    i = 0;

    if (str[i] == '-')
        i++;

    for (; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
            return (0);
    }

    return (1);
}
