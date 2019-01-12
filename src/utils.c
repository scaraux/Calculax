#include <stdio.h>
#include <ctype.h>
#include "interpreter.h"

int     isNumber(char *str)
{
    while (*str != '\0')
    {
        if (isdigit(*str) == 0)
        {
            return(0);
        }
        ++str;
    }
    return(1);
}