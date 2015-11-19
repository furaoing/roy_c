#include <stdio.h>
#include <stdlib.h>


struct node
{
    int key_value;
    struct node *left;
    struct node *right;
};

struct node* root = 0;

void insert(int key, struct node** leaf)
{
    if(*leaf == 0)
    {
        *leaf = (struct node*) malloc(sizeof(struct node));
        printf("leaf address: %d\n", *leaf);
        (*leaf)->key_value = key;
        (*leaf)->left = 0;
        (*leaf)->right = 0;
        printf("leaf value: %d\n", (*leaf)->key_value);
    }

    else if(key < (*leaf)->key_value)
    {
        insert(key, &((*leaf)->left));
    }
    else if(key > (*leaf)->key_value)
    {
        insert(key, &((*leaf)->right));
    }
}

void destroy_tree(struct node* leaf)
{
    if (leaf!=0)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        free(leaf);
    }
}

struct node* search(int key, struct node* leaf)
{
    if(leaf!=0)
    {
        if(leaf->key_value==key) return leaf;
        else if(leaf->key_value<key) return search(key, leaf->right);
        else if(leaf->key_value>key) return search(key, leaf->left);
    }
    else return 0;
}
