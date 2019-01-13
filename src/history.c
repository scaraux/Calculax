#include <stdlib.h>
#include <string.h>
#include "interpreter.h"

int             add_element_to_history(t_history **list, char *element)
{
    t_history   *new_elem;

    new_elem = malloc(sizeof(*new_elem));
    if (new_elem == NULL)
        return(-1);
    new_elem->line = strdup(element);
    new_elem->next = *list;
    new_elem->prev = NULL;

    if ((*list) != NULL)
    {
        (*list)->prev = new_elem;
    }
    else {
        new_elem->end = 1;
    }

    (*list) = new_elem;
    return(0);
}

int             add_ptr_to_history(t_history **list, char *element)
{
    t_history   *new_elem;

    new_elem = malloc(sizeof(*new_elem));
    if (new_elem == NULL)
        return(-1);
    new_elem->line = element;
    new_elem->next = *list;
    new_elem->prev = NULL;

    if ((*list) != NULL)
    {
        (*list)->prev = new_elem;
    }
    else {
        new_elem->end = 1;
    }

    (*list) = new_elem;
    return(0);
}
