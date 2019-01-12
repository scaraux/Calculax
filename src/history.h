#ifndef		            _HISTORY_H_
#define	                _HISTORY_H_

typedef struct	        s_history
{
    char                end;
    char		        *line;
    struct s_history    *prev;
    struct s_history 	*next;
}		                t_history;

int		                add_element_to_history(t_history **list, char *element);

#endif		            /* _HISTORY_H_ */

