#ifndef		            _INTERPRETER_H_
#define	                _INTERPRETER_H_

#include                <signal.h>

#define                 PROMPT              "> "
#define                 MSG_STORE_SUCESS    "Success!"
#define                 MSG_FORMAT_ERROR    "Oops! Format error."

#define                 BUFF_LENGHT         256

typedef struct	        s_cursor
{
    int		            x;
    int		            y;
}		                t_cursor;

typedef struct	        s_memory
{
    char		        *var_name;
    int		            var_value;
    struct s_memory	    *next;
}		                t_memory;


typedef struct	        s_hist
{
    char                end;
    char		        line[BUFF_LENGHT];
    struct s_hist       *prev;
    struct s_hist    	*next;
}		                t_hist;

typedef                 void (*t_key_action)(t_hist **head, t_hist **curr, t_cursor *cursor, t_memory **memory, int c);

int                     calculax();
int                     configure(t_cursor *cursor);
int                     parse(char *buffer, t_memory **memory, t_cursor *cursor);
int                     parse_key_pad(int c);
int                     store(char **tokens, t_memory **memory);

int                     get_array_size(char **tokens);
int                     calculate(char **tokens, t_memory **memory);
int                     set_operand(int *operand, char *str, t_memory **memory);

void                    handle_key(t_hist **head, t_hist **curr, t_cursor *cursor, t_memory **memory, int c);
void                    handle_key_up(t_hist **head, t_hist **curr, t_cursor *cursor, t_memory **memory, int c);
void                    handle_key_down(t_hist **head, t_hist **curr, t_cursor *cursor, t_memory **memory, int c);
void                    handle_key_right(t_hist **head, t_hist **curr, t_cursor *cursor, t_memory **memory, int c);
void                    handle_key_left(t_hist **head, t_hist **curr, t_cursor *cursor, t_memory **memory, int c);
void                    handle_key_tab(t_hist **head, t_hist **curr, t_cursor *cursor, t_memory **memory, int c);
void                    handle_key_return(t_hist **history, t_hist **history_cursor, t_cursor *cursor, t_memory **memory, int c);
int                     configure_actions(t_key_action **actions);
void                    free_actions(t_key_action **actions);

int		                add_variable_to_mem(t_memory **list, char *name, int value);
int                     get_variable(t_memory **memory, char *name);
char                    *get_matching_variable(t_memory **memory, char *name);
void                    dump_memory(t_memory **memory);

int                     insert_element_to_history(t_hist **list, char *element);
void                    free_history(t_hist **head);

char                    **split_line(char *str, char c);
int                     count_tokens(char *str, char c);

#endif		        /* _INTERPRETER_H_ */