//função para criar um nó de uma lista
Node *createNode(int key)
{
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->key = key;

    return node;
}

//função para criar uma lista
List *createList()
{
    List *l = malloc(sizeof(List));
    l->head = NULL;

    return l;
}
