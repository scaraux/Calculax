#include <stdlib.h>
#include <string.h>
#include "interpreter.h"

// int             add_element_to_history(t_hist **list, char *element)
// {
//     t_hist   *new_elem;

//     new_elem = malloc(sizeof(*new_elem));
//     if (new_elem == NULL)
//         return(-1);
//     new_elem->line = strdup(element);
//     new_elem->next = *list;
//     new_elem->prev = NULL;

//     if ((*list) != NULL)
//     {
//         (*list)->prev = new_elem;
//     }
//     else {
//         new_elem->end = 1;
//     }

//     (*list) = new_elem;
//     return(0);
// }

int             insert_element_to_history(t_hist **list, char *element)
{
    t_hist   *new_elem;

    new_elem = malloc(sizeof(*new_elem));
    if (new_elem == NULL)
        return(-1);

    memset(new_elem->line, 0, BUFF_LENGHT);
    strcpy(new_elem->line, element);

    new_elem->next = NULL;
    new_elem->prev = *list;

    if ((*list) != NULL)
    {
        new_elem->next = (*list)->next;

        if ((*list)->next != NULL)
        {
            (*list)->next->prev = new_elem;
        }
        (*list)->next = new_elem;
    }
    else
    {
        (*list) = new_elem;
    }

    return(0);
}

void            free_history(t_hist **head)
{
   t_hist       *tmp;

   while (*head != NULL)
    {
       tmp = *head;
       *head = (*head)->next;
       free(tmp);
    }
}

void             dump_history(t_hist **head)
{
    t_hist    *tmp;

    tmp = *head;
    while (tmp != NULL)
    {
        // printf("%s\n", tmp->line);
        tmp = tmp->next;
    }
}