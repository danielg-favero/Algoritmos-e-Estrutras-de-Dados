//Verificar se a fila está vazia
int queueIsEmpty(Queue *q)
{
    return q == NULL || q->begin == NULL;
}

void enqueue(Queue *q, int key)
{
    Node *aux = createNode(key);
    
    //CASO 1: Inserção do primeiro nó
    if (queueIsEmpty(q))
    {
        q->begin = aux;
        q->end = aux;
    }
    else
    {
        //CASO 2: Inserção em qualquer lugar
        q->end->next = aux;
        q->end = q->end->next;
    }
}
