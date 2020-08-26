#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    int key;
    Node *left;
    Node *right;
};

Node *createNode(int key)
{
    Node *n = malloc(sizeof(Node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void freeTree(Node *tree)
{
    if (tree != NULL)
    {
        //percorrer os dois ramos da arvore até chegar nas suas folhas
        freeTree(tree->left);
        freeTree(tree->right);
        free(tree);
    }
}
