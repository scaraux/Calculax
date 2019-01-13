#include <stdlib.h>
#include <stdio.h>
#include "interpreter.h"

int                 get_array_size(char **tokens)
{
    int             count = 0;

    while (*tokens != NULL)
    {
        ++count;
        ++tokens;
    }
    return count;
}

int                 set_operand(int *operand, char *str, t_memory **memory)
{
    int             tmp;

    if (isNumber(str))
    {
        *operand = atoi(str);
        return(1);
    }
    tmp = get_variable(memory, str);
    if (tmp == -1)
    {
        printf("Oops, the variable %s does not exist\n", str);
        return(-1);
    }
    *operand = tmp;
    return(1);
}

int                 calculate(char **tokens, t_memory **memory)
{
    int             i = 0;
    int             result;
    int             left;
    int             right;
    int             token_count;

    token_count = get_array_size(tokens);

    if (set_operand(&left, tokens[i], memory) == -1)
        return(-1);
    if (set_operand(&right, tokens[i + 2], memory) == -1)
        return(-1);

    result = left + right;

    i += 3;
    while (i < token_count)
    {
        if (set_operand(&right, tokens[i + 1], memory) == -1)
            return(-1);
        result = (result + right);
        i += 2;
    }
    return result;
}