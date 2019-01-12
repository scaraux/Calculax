#ifndef		        _ACTIONS_H_
#define	            _ACTIONS_H_

#include            "memory.h"
#include            "history.h"
#include            "interpreter.h"

typedef             void (*t_key_action)(t_history **history, t_cursor *cursor, t_memory **memory, int c);

int                 configure_actions(t_key_action **actions);
void                handle_key(t_history **history, t_cursor *cursor, t_memory **memory, int c);
void                handle_key_up(t_history **history, t_cursor *cursor, t_memory **memory, int c);
void                handle_key_down(t_history **history, t_cursor *cursor, t_memory **memory, int c);
void                handle_key_right(t_history **history, t_cursor *cursor, t_memory **memory, int c);
void                handle_key_left(t_history **history, t_cursor *cursor, t_memory **memory, int c);
void                handle_key_tab(t_history **history, t_cursor *cursor, t_memory **memory, int c);

void                handle_key_return(t_history **history, t_history **history_cursor, t_cursor *cursor, t_memory **memory, int c);

#endif		        /* _ACTIONS_H_ */
