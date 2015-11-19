//
// Created by rao on 15-11-14.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct tf
{
    char* term;
    int frequency;
    struct tf *next;
};

// root represents the entire linked list;

char* tokenize(char* content, int len) {
    size_t malloc_size = (size_t) (2*(len-1)+1);
    char* token_candidate = (char*) malloc(malloc_size);
    for (int i = 0; i < (len-2); i++)
    {
        *(token_candidate+2*i) = content[i];
        *(token_candidate+2*i+1) = content[i+1];
    }

    return token_candidate;
}

struct tf* search(struct tf* node, char* term)
{
    if (node == 0)
        return 0;
    else if (strcmp(node->term, term) == 0)
        return node;
    else
        return search(node->next, term);
}

void append(struct tf* node, char* term)
{
    struct tf* tail = (struct tf*) malloc(sizeof(struct tf));
    (tail->term) = term;
    (tail->frequency) = 1;
    (tail->next) = 0;
    if ((node->next) == 0)
        (node->next) = tail;
    else
        return append(node->next, term);
}

void update(struct tf* node)
{
    (node->term) += 1;
}

void update_list(struct tf* root, char* term)
{
    struct tf* search_result = search(root, term);
    if (search_result == 0)
        append(root, term);
    else
        update(search_result);
}

void free_list(struct tf* node)
{
    if (node==0)
    {
        return;
    }
    else
    {
        free(node);
        free_list(node->next);
    }
}

void construct_tf(struct tf* root, char* token_candidate, int index, int len)
{
    char token[3] = {*(token_candidate + 2*index), *(token_candidate + 2*index + 1)};
    char* p_token = &token[0];
    if (index == len)
        return;
    else
    {
        if (index == 0) {
            root = (struct tf *) malloc(sizeof(struct tf));
            root->term = p_token;
            root->frequency = 1;
            root->next = 0;
        }
        else if (index < len) {
            update_list(root, p_token);
        }

        index += 1;
        return construct_tf(root, token_candidate, index, len);
    }
}

struct tf* get_tf(char* s, int len)
{
    char* tokens = tokenize(s, len);
    struct tf* root = 0;
    construct_tf(root, tokens, 0, len);
    free(tokens);
    free_list(root);
    return root;
}

