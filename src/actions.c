#include <stdlib.h>
#include <curses.h>
#include <string.h>
#include <signal.h>
#include "interpreter.h"

int                 configure_actions(t_key_action **actions)
{
    *actions = (t_key_action*) malloc(sizeof(t_key_action) * 7);
    if (actions == NULL)
    {
        return(-1);
    }
    (*actions)[0] = handle_key_up;
    (*actions)[1] = handle_key_down;
    (*actions)[2] = handle_key_left;
    (*actions)[3] = handle_key_right;
    (*actions)[4] = handle_key_tab;
    (*actions)[5] = handle_key;
    (*actions)[6] = NULL;
    return(0);
}

void                free_actions(t_key_action **actions)
{
    free(*actions);
}

void                update_prompt_and_buffer(t_cursor *cursor, char *line)
{
    move(cursor->y, 0);
    clrtoeol();
    printw("%s%s", PROMPT, line);
}

void                handle_key(t_hist **head, t_hist **curr, t_cursor *cursor, t_memory **memory, int c)
{
    char            tmp[2];

    tmp[0] = c;
    tmp[1] = '\0';

    addch(c);
    strcat((*head)->line, tmp);
}

void                handle_key_up(t_hist **head, t_hist **curr, t_cursor *cursor, t_memory **memory, int c)
{
    char            *new_buffer;

    if ((*curr)->next != NULL)
    {
        *curr = (*curr)->next;
        new_buffer = (*curr)->line;
        update_prompt_and_buffer(cursor, new_buffer);
    }
}

void                handle_key_down(t_hist **head, t_hist **curr, t_cursor *cursor, t_memory **memory, int c)
{
    char            *new_buffer;

    if ((*curr)->prev != NULL)
    {
        *curr = (*curr)->prev;
        new_buffer = (*curr)->line;
        update_prompt_and_buffer(cursor, new_buffer);
    }
}

void                handle_key_left(t_hist **head, t_hist **curr, t_cursor *cursor, t_memory **memory, int c)
{
    cursor->x -= 1;
    move(cursor->y, cursor->x);
}

void                handle_key_right(t_hist **head, t_hist **curr, t_cursor *cursor, t_memory **memory, int c)
{
    cursor->x += 1;
    move(cursor->y, cursor->x);
}

void                handle_key_tab(t_hist **head, t_hist **curr, t_cursor *cursor, t_memory **memory, int c)
{
    char *completion = get_matching_variable(memory, "toto");
    printw("%s", completion);
    cursor->y += 1;
}

void                handle_key_return(t_hist **head, t_hist **curr, t_cursor *cursor, t_memory **memory, int c)
{
    char            *buffer_to_eval;

    addch(c);

    buffer_to_eval = (*curr)->line;

    // parse(buffer_to_eval, memory, cursor);

    insert_element_to_history(head, buffer_to_eval);

    memset((*head)->line, 0, BUFF_LENGHT);

    *curr = *head;

    printw("%s", PROMPT);

    cursor->x = 0;
    cursor->y += 1;
}
