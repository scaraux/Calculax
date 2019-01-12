#include <stdio.h>
#include <ctype.h>

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