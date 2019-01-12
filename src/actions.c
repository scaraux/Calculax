#include "actions.h"
#include <stdlib.h>
#include <curses.h>
#include <string.h>

int reached_end = 0;

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

void                update_prompt_and_buffer(t_cursor *cursor, char *line)
{
    // Move cursor to beggining of line
    move(cursor->y, 0);
    // Clear line
    clrtoeol();
    // move(cursor->y, cursor->x);
    // Print prom
    printw("%s %s", PROMPT, line);
    // Copy new selected line into buffer
    strcpy(cursor->buffer, line);
}

void                handle_key(t_history **history, t_cursor *cursor, t_memory **memory, int c)
{
    addch(c);
    cursor->buffer[cursor->x] = c;
    cursor->x += 1;
}

void                handle_key_up(t_history **history, t_cursor *cursor, t_memory **memory, int c)
{
    if (*history == NULL)
        return;
    if ((*history)->next != NULL)
    {
        *history = (*history)->next;
        update_prompt_and_buffer(cursor, (*history)->line);
    }
}

void                handle_key_down(t_history **history, t_cursor *cursor, t_memory **memory, int c)
{
    if (*history == NULL)
        return;
    if ((*history)->prev != NULL)
    {
        *history = (*history)->prev;
        update_prompt_and_buffer(cursor, (*history)->line);
    }
}

void                handle_key_left(t_history **history, t_cursor *cursor, t_memory **memory, int c)
{
    cursor->x -= 1;
    move(cursor->y, cursor->x);
}

void                handle_key_right(t_history **history, t_cursor *cursor, t_memory **memory, int c)
{
    cursor->x += 1;
    move(cursor->y, cursor->x);
}

void                handle_key_tab(t_history **history, t_cursor *cursor, t_memory **memory, int c)
{
    char *completion = get_matching_variable(memory, "toto");
    printw("%s", completion);
    cursor->y += 1;
}

void                handle_key_return(t_history **history_head, t_history **history_cursor, t_cursor *cursor, t_memory **memory, int c)
{
    addch(c);

    // First element is now buffer content
    strcpy((*history_head)->line, cursor->buffer);
    // Parse
    // parse(memory, cursor);
    // Set buffer to empty
    memset(cursor->buffer, 0, sizeof(cursor->buffer));

    add_element_to_history(history_head, cursor->buffer);

    *history_cursor = *history_head;

    printw("%s", PROMPT);
    cursor->x = 0;
    cursor->y += 1;
}
