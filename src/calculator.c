#include "interpreter.h"

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