#ifndef		        _INTERPRETER_H_
#define	            _INTERPRETER_H_

#include            "memory.h"
#include            "history.h"

#define             PROMPT              "> "
#define             MSG_STORE_SUCESS    "Success!"
#define             MSG_FORMAT_ERROR    "Oops! Format error."

typedef struct	    s_cursor
{
    int		        x;
    int		        y;
    char            buffer[4096];
}		            t_cursor;

int                 configure(t_cursor *cursor);

int                 eval();
int                 parse(t_memory **memory, t_cursor *cursor);
int                 calculate(char **tokens, t_memory **memory);
int                 store(char **tokens, t_memory **memory);
int                 set_operand(int *operand, char *str, t_memory **memory);

#endif		        /* _INTERPRETER_H_ */