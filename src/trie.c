#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "trie.h"
#include "utils.h"

int         add_suggestion(t_sugg **head, char *suggestion)
{
    t_sugg  *new_elem;
    t_sugg  *tmp = *head;

    new_elem = malloc(sizeof(*new_elem));
    if (new_elem == NULL)
        return(-1);

    new_elem->str = strdup(suggestion);
    new_elem->next = NULL;

    if ((*head) == NULL)
    {
        *head = new_elem;
        return(0);
    }
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = new_elem;
    return(0);
}

t_trie      *get_trie_node(void)
{
    t_trie  *pNode = NULL;

    pNode = (t_trie *)malloc(sizeof(t_trie));

    if (pNode)
    {
        int i;

        pNode->isEndOfWord = false;

        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }

    return pNode;
}

void        insert_key_to_trie(t_trie *root, const char *key)
{
    int     level;
    int     length = strlen(key);
    int     index;
    t_trie  *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
        {
            pCrawl->children[index] = get_trie_node();
        }
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

bool        search_key_from_trie(t_trie *root, const char *key)
{
    int     level;
    int     length = strlen(key);
    int     index;
    t_trie  *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);

        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

// Returns 0 if current node has a child
// If all children are NULL, return 1.
bool        is_last_node(t_trie *root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i] != NULL)
        {
            return 0;
        }
    }
    return 1;
}


// Recursive function to print auto-suggestions for given
// node.
void        suggestions_rec(t_trie *root, t_sugg **suggestions, char *curr_prefix)
{
    // found a string in Trie with the given prefix
    if (root->isEndOfWord)
    {
        add_suggestion(suggestions, curr_prefix);
    }
    // All children struct node pointers are NULL
    if (is_last_node(root))
    {
        return;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i] != NULL)
        {
            // append current character to currPrefix string
            append_char_to_string(curr_prefix, 97 + i);
            // recur over the rest
            suggestions_rec(root->children[i], suggestions, curr_prefix);
            // remove last character
            curr_prefix[strlen(curr_prefix) - 1] = 0;
        }
    }
}

// print suggestions for given query prefix.
t_sugg      *get_auto_suggestions(t_trie *root, char *query)
{
    t_sugg  *head = NULL;
    t_trie  *pCrawl = root;

    // Check if prefix is present and find the
    // the node (of last level) with last character
    // of given string.
    int level;
    int n = strlen(query);
    for (level = 0; level < n; level++)
    {
        int index = CHAR_TO_INDEX(query[level]);
        // no string in the Trie has this prefix
        if (!pCrawl->children[index])
        {
            return head;
        }
        pCrawl = pCrawl->children[index];
    }

    // If prefix is present as a word.
    bool isWord = (pCrawl->isEndOfWord == true);
    // If prefix is last node of tree (has no
    // children)
    bool isLast = is_last_node(pCrawl);
    // If prefix is present as a word, but
    // there is no subtree below the last
    // matching node.
    if (isWord && isLast)
    {
        printf(">%s\n", query);
        return head;
    }
    // If there are are nodes below last
    // matching character.
    if (!isLast)
    {
        char *prefix = strdup(query);
        suggestions_rec(pCrawl, &head, prefix);
    }
    return head;
}

int         main()
{
    t_trie *root = get_trie_node();

    insert_key_to_trie(root, "hello");
    insert_key_to_trie(root, "dog");
    insert_key_to_trie(root, "hell");
    insert_key_to_trie(root, "cat");
    insert_key_to_trie(root, "a");
    insert_key_to_trie(root, "hel");
    insert_key_to_trie(root, "help");
    insert_key_to_trie(root, "helps");
    insert_key_to_trie(root, "helping");

    t_sugg *suggestions = get_auto_suggestions(root, "hel");

    while (suggestions != NULL)
    {
        printf("%s\n", suggestions->str);
        suggestions = suggestions->next;
    }
    return 0;
}

void        search_driver()
{
    // Input keys (use only 'a' through 'z' and lower case)
    // char keys[][8] = {"the", "a", "there", "answer", "any",
    //                  "by", "bye", "their"};

    // char output[][32] = {"Not present in trie", "Present in trie"};


    // t_trie *root = getNode();

    // int i;
    // for (i = 0; i < ARRAY_SIZE(keys); i++)
    // {
    //     insert(root, keys[i]);
    // }

    // printf("%s --- %s\n", "the", output[search(root, "the")] );
    // printf("%s --- %s\n", "these", output[search(root, "these")] );
    // printf("%s --- %s\n", "their", output[search(root, "their")] );
    // printf("%s --- %s\n", "thaw", output[search(root, "thaw")] );
}