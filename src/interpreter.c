#include            <stdio.h>
#include            <stdlib.h>
#include            <string.h>
#include            <curses.h>
#include            <termios.h>
#include            "interpreter.h"


int                 store(char **tokens, t_memory **memory)
{
    char            *var_name;
    int             var_value;

    var_name = tokens[0];
    var_value = atoi(tokens[2]);

    if (add_variable_to_mem(memory, var_name, var_value) == -1)
    {
        return(-1);
    }
    return(1);
}

int                 configure(t_cursor *cursor)
{
    memset(cursor->buffer, 0, sizeof(cursor->buffer));

    cursor->x = 0;
    cursor->y = 0;

    initscr();
    keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	cbreak();
	noecho();

    // struct          termios info;
    // tcgetattr(0, &info);          /* get current terminal attirbutes; 0 is the file descriptor for stdin */
    // info.c_lflag &= ~ICANON;  /* disable canonical mode */
    // info.c_lflag &= ~ECHO;
    // info.c_cc[VMIN] = 1;          /* wait until at least one keystroke available */
    // info.c_cc[VTIME] = 0;         /* no timeout */
    // tcsetattr(0, TCSANOW, &info); /* set immediately */

    return(0);
}

int                 parse(t_memory **memory, t_cursor *cursor)
{
    char            **tokens = NULL;
    int             token_count;
    int             result;
    size_t          size;

    tokens = split_line(cursor->buffer, ' ');
    token_count = get_array_size(tokens);
    if ((token_count < 3) || (token_count % 2) == 0)
    {
        printw("%s\n", MSG_FORMAT_ERROR);
        cursor->y += 1;
        return(-1);
    }

    if (strcmp(tokens[1], "=") == 0)
    {
        if ((store(tokens, memory)) == -1)
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
        case '\t':
            return 4;
        case 10:
            return 6;
        default:
            return 5;
    }
}

int                 eval()
{
    t_cursor        cursor;
    t_key_action    *actions;
    t_history       *history_cursor = NULL;
    t_history       *history_head = NULL;
    t_memory        *memory = NULL;
    int             c;

    memset(first, 0, sizeof(first));
    configure(&cursor);
    configure_actions(&actions);

    add_element_to_history(&history_head, "oscar = 3");
    add_element_to_history(&history_head, "oscar = 2");
    add_element_to_history(&history_head, "");
    // add_ptr_to_history(&history_head, cursor.buffer);

    history_cursor = history_head;

    printw("%s", PROMPT);
    while (42)
    {
        c = getch();

        int code = parse_key_pad(c);

        if (code == 6)
        {
            handle_key_return(&history_head, &history_cursor, &cursor, &memory, c);
        }
        else {
            actions[code](&history_cursor, &cursor, &memory, c);
        }
    }
    endwin();
    return (1);
}

