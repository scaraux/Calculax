#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

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

char        *string_difference(char *s1, char *s2)
{
    int     size;
    char    *ret;
    char    *tmp;

    int     s1_size = strlen(s1);
    int     s2_size = strlen(s2);

    size = (s1_size > s2_size) ? s1_size - s2_size : s2_size - s1_size;

    if (size == 0)
        return NULL;

    ret = (char*) malloc(sizeof(char) * size + 1);
    if (ret == NULL)
        return NULL;

    while (*s1 != '\0' && *s2 != '\0')
    {
        ++s1;
        ++s2;
    }
    tmp = *s1 == '\0' ? s2 : s1;
    strcpy(ret, tmp);
    return ret;
}

char        *get_last_word(char *str)
{
    char *p = strrchr(str, ' ');
    if (p && *(p + 1))
    {
        return strdup(p + 1);
    }
    return strdup(str);
}