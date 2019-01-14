#include            <stdio.h>
#include            <stdlib.h>
#include            <string.h>
#include            <curses.h>
#include            <termios.h>
#include            "interpreter.h"

char                eval = 1;
void                sigint_handler(int);

int                 store(char **tokens, t_memory **memory, t_trie **trie)
{
    char            *var_name;
    int             var_value;

    var_name = tokens[0];
    var_value = atoi(tokens[2]);

    insert_key_to_trie((*trie), var_name);
    if (add_variable_to_mem(memory, var_name, var_value) == -1)
    {
        return(-1);
    }
    return(1);
}

int                 configure(t_cursor *cursor)
{
    signal(SIGINT, sigint_handler);

    cursor->x = 0;
    cursor->y = 0;

    initscr();
    keypad(stdscr, TRUE);
	cbreak();
	noecho();
    timeout(10);
    return(0);
}

int                 parse(char *buffer, t_memory **memory, t_cursor *cursor, t_trie **trie)
{
    char            **tokens = NULL;
    int             token_count;
    int             result;
    size_t          size;

    tokens = split_line(buffer, ' ');
    token_count = get_array_size(tokens);
    if ((token_count < 3) || (token_count % 2) == 0)
    {
        printw("%s\n", MSG_FORMAT_ERROR);
        cursor->y += 1;
        return(-1);
    }

    if (strcmp(tokens[1], "=") == 0)
    {
        if ((store(tokens, memory, trie)) == -1)
            return(-1);
        printw("%s\n", MSG_STORE_SUCESS);
        cursor->y += 1;
    }
    else {
        if ((result = calculate(tokens, memory)) != -1)
        printw("%d\n", result);
        cursor->y += 1;
    }
    return(1);
}

int                 parse_key_pad(int c)
{
    switch(c)
    {
        case KEY_UP:
            return 0;
        case KEY_DOWN:
            return 1;
        case KEY_LEFT:
            return 2;
        case KEY_RIGHT:
            return 3;
        case 127:
            return 4;
        default:
            return 5;
    }
}

int                 calculax()
{
    t_cursor        cursor;
    t_key_action    *actions;
    t_hist          *curr = NULL;
    t_hist          *head = NULL;
    t_memory        *memory = NULL;
    t_trie          *trie = get_trie_node();

    int             c;
    int             code;

    configure(&cursor);
    configure_actions(&actions);
    insert_element_to_history(&head, "");

    curr = head;
    printw("%s", PROMPT);
    while (eval == 1)
    {
        if ((c = getch()) != ERR)
        {
            code = parse_key_pad(c);
            if (c == 10)
            {
                handle_key_return(&head, &curr, &cursor, &memory, &trie, c);
            }
            else if (c == '\t')
            {
                handle_key_tab(&head, &curr, &cursor, &memory, &trie, c);
            }
            else
            {
                actions[code](&head, &curr, &cursor, &memory, c);
            }
        }
    }
    endwin();
    free_history(&head);
    free_actions(&actions);
    return (0);
}

void sigint_handler(int sig)
{
    eval = 0;
    printw("%s\n", LAST_MSG);
}
