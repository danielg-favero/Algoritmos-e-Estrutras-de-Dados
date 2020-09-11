//criar um nó
Node *create(int key)
{
    Node *node = malloc(sizeof(Node));
    node->father = NULL;
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    node->color = 0; //Todo nó inserido é vermelho

    return node;
}
