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

//em uma arvore binária
//os elementos que são menores que o nó pai são colocados no ramo ou subramo esquerdo
//os elementos que são maiores que o nó pau são colocads no ramo ou subramo direito
Node *insert(Node *tree, int key)
{
    if (tree == NULL)
    {
        tree = createNode(key);
    }
    else if (key < tree->key)
    {
        tree->left = insert(tree->left, key);
    }
    else
    {
        tree->right = insert(tree->right, key);
    }

    return tree;
}
