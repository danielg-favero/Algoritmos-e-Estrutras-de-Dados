//criar uma página
Node *create()
{
    Node *node = malloc(sizeof(Node));
    node->numberOfKeys = 0;
    node->isLeaf = true;
    node->order = N;

    int i;
    for (i = 0; i < N; i++)
    {
        //iniciar todos os filhos com nulo
        node->children[i] = NULL;
    }

    return node;
}
