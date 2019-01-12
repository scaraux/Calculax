#include        <stdlib.h>
#include        <string.h>
#include        <stdio.h>
#include        "memory.h"

int		          add_variable_to_mem(t_memory **memory, char *name, int value)
{
  t_memory	    *new_elem;

  new_elem = malloc(sizeof(*new_elem));
  if (new_elem == NULL)
  {
    return(-1);
  }
  new_elem->var_name = strdup(name);
  new_elem->var_value = value;
  new_elem->next = *memory;
  *memory = new_elem;
  return (0);
}

int             get_variable(t_memory **memory, char *name)
{
    t_memory    *tmp;

    tmp = *memory;
    while (tmp != NULL)
    {
        if (strcmp(tmp->var_name, name) == 0)
        {
          return tmp->var_value;
        }
        tmp = tmp->next;
    }
    return(-1);
}
void             dump_memory(t_memory **memory)
{
    t_memory    *tmp;

    tmp = *memory;
    while (tmp != NULL)
    {
        printf("%s = %d\n", tmp->var_name, tmp->var_value);
        tmp = tmp->next;
    }
}

char             *get_matching_variable(t_memory **memory, char *name)
{
    return "oscar";
}
