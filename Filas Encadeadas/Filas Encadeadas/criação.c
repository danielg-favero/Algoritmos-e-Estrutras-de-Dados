//Criar nó de uma fila
Node *createNode(int key)
{
    Node *node = malloc(sizeof(Node)); //Alocar memória para a estrutura de um nó
    node->key = key;
    node->next = NULL;

    return node;
}

//Criar uma fila
Queue *createQueue()
{
    Queue *q = malloc(sizeof(Queue)); //Alocar memória para a estrutura de uma fila
    q->begin = NULL;
    q->end = NULL;

    return q;
}
