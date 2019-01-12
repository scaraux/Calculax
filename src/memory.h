#ifndef		            _MEMORY_H_
#define	                _MEMORY_H_

typedef struct	        s_memory
{
    char		        *var_name;
    int		            var_value;
    struct s_memory	    *next;
}		                t_memory;

int		                add_variable_to_mem(t_memory **list, char *name, int value);
int                     get_variable(t_memory **memory, char *name);
char                    *get_matching_variable(t_memory **memory, char *name);
void                    dump_memory(t_memory **memory);


#endif		            /* _MEMORY_H_ */