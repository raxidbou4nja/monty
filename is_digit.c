#include "monty.h"

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