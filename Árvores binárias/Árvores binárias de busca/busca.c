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

Node *search(Node *tree, int key)
{
    if (tree != NULL)
    {
        if (tree->key == key)
        {
            return tree;
        }
        else if (key < tree->key)
        { //se o valor for menor que o nó pai, percorrer o ramo esquerdo
            return search(tree->left, key);
        }
        else
        { //se o valor for mairo que o nó pai, percorrer o ramo direito
            return search(tree->right, key);
        }
    }
}
