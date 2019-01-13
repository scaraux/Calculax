#ifndef		            _INTERPRETER_H_
#define	                _INTERPRETER_H_

#define                 PROMPT              "> "
#define                 MSG_STORE_SUCESS    "Success!"
#define                 MSG_FORMAT_ERROR    "Oops! Format error."

char first[4096];


typedef struct	        s_cursor
{
    int		            x;
    int		            y;
    char                buffer[4096];
}		                t_cursor;

typedef struct	        s_memory
{
    char		        *var_name;
    int		            var_value;
    struct s_memory	    *next;
}		                t_memory;


typedef struct	        s_history
{
    char                end;
    char		        *line;
    struct s_history    *prev;
    struct s_history 	*next;
}		                t_history;

typedef                 void (*t_key_action)(t_history **history, t_cursor *cursor, t_memory **memory, int c);

int                     configure(t_cursor *cursor);

int                     eval();
int                     parse(t_memory **memory, t_cursor *cursor);
int                     parse_key_pad(int c);
int                     store(char **tokens, t_memory **memory);

int                     get_array_size(char **tokens);
int                     calculate(char **tokens, t_memory **memory);
int                     set_operand(int *operand, char *str, t_memory **memory);

int                     configure_actions(t_key_action **actions);
void                    handle_key(t_history **history, t_cursor *cursor, t_memory **memory, int c);
void                    handle_key_up(t_history **history, t_cursor *cursor, t_memory **memory, int c);
void                    handle_key_down(t_history **history, t_cursor *cursor, t_memory **memory, int c);
void                    handle_key_right(t_history **history, t_cursor *cursor, t_memory **memory, int c);
void                    handle_key_left(t_history **history, t_cursor *cursor, t_memory **memory, int c);
void                    handle_key_tab(t_history **history, t_cursor *cursor, t_memory **memory, int c);

void                    handle_key_return(t_history **history, t_history **history_cursor, t_cursor *cursor, t_memory **memory, int c);

int		                add_variable_to_mem(t_memory **list, char *name, int value);
int                     get_variable(t_memory **memory, char *name);
char                    *get_matching_variable(t_memory **memory, char *name);
void                    dump_memory(t_memory **memory);

int		                add_element_to_history(t_history **list, char *element);
int                     add_ptr_to_history(t_history **list, char *element);

char                    **split_line(char *str, char c);
int                     count_tokens(char *str, char c);

int                     isNumber(char *str);

#endif		        /* _INTERPRETER_H_ */