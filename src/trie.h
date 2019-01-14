#ifndef		            _TRIE_H_
#define	                _TRIE_H_

#include                <stdbool.h>

#define                 ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

#define                 ALPHABET_SIZE (26)

#define                 CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef struct          s_trie_node
{
    struct s_trie_node  *children[ALPHABET_SIZE];
    bool                isEndOfWord;
}                       t_trie;

typedef struct          s_suggestion
{
    char                *str;
    struct s_suggestion *next;
}                       t_sugg;

void                    insert_key_to_trie(t_trie *root, const char *key);
bool                    search_key_from_trie(t_trie *root, const char *key);
t_trie                  *get_trie_node(void);
bool                    is_last_node(t_trie *root);
void                    suggestions_rec(t_trie *root, t_sugg **suggestions, char *curr_prefix);
t_sugg                  *get_auto_suggestions(t_trie *root, char *query);


#endif		            /* _TRIE_H_ */