#include    <stdio.h>
#include    <ctype.h>
#include    <string.h>
#include    "utils.h"

int         is_number(char *str)
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

void        append_char_to_string(char *str, char c)
{
    char    tmp[2];
    tmp[0] = c;
    tmp[1] = 0;
    strcat(str, tmp);
}