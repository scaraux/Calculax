#include    <stdlib.h>
#include    <stdio.h>
#include    <string.h>
#include    <unistd.h>
#include    "interpreter.h"

int         count_tokens(char *str, char c) {
    int     tokens = 1;

    while (*str != '\0')
    {
        if (*str == c)
        {
            ++tokens;
        }
        ++str;
    }
    return(tokens);
}

char         **split_line(char *str, char c)
{
    int     token_count = 0;
    int     token_len = 1;
    int     i = 0;
    int     j = 0;
    int     k = 0;
    char    *p;
    char    *t;
    char    **tokens;

    token_count = count_tokens(str, c);

    tokens = (char**) malloc(sizeof(char*) * token_count + 1);
    if (tokens == NULL)
        exit(1);

    while (str[j] != '\0')
    {
        if (str[j] == c)
        {
            tokens[i] = (char*) malloc( sizeof(char) * token_len );
            if (tokens[i] == NULL)
                exit(1);

            token_len = 0;
            i++;
        }
        j++;
        token_len++;
    }

    tokens[i] = (char*) malloc( sizeof(char) * token_len );
    if (tokens[i] == NULL)
        exit(1);

    i = 0;
    p = str;
    t = tokens[i];
    while (*p != '\0')
    {
        if (*p != c && *p != '\0')
        {
            *t = *p;
            t++;
        }
        else
        {
            *t = '\0';
            i++;
            t = tokens[i];
        }
        p++;
    }

    tokens[token_count] = NULL;

    return tokens;
}
