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

Node *delete (Node *tree, int key)
{
    Node *aux, *dad, *children;

    if (tree != NULL)
    {
        //procurar o valor para remover
        if (key < tree->key)
        {
            tree->left = delete (tree->left, key);
        }
        else if (key > tree->key)
        {
            tree->right = delete (tree->right, key);
        }
        else
        {
            aux = tree;

            if (tree->left == NULL)
            {
                //1º CASO:
                //caso o nó escolhido tenha um ou nenhum filho
                tree = tree->right;
            }
            else if (tree->right == NULL)
            {
                //2º CASO:
                //caso o nó escolhido tenha apenas um filho (direito)
                tree = tree->left;
            }
            else
            {
                //3º CASO:
                //caso o nó escolhido tenha dois filhos
                dad = aux->right;
                children = dad;

                while (children->left != NULL)
                {
                    dad = children;
                    children = children->left;
                }

                if (children != dad)
                {
                    dad->left = children->right;
                    children->right = aux->right;
                }

                children->left = aux->left;
                tree = children;
            }
        }
        return tree;
    }
}
