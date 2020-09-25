//Verificar se uma lista encadeada está vazia
int isEmpty(List *l)
{
    return (l == NULL) || (l->head == NULL);
}

//função para inserir itens em uma lista encadeada
void insertNode(List *l, int key)
{
    Node *aux;
  
    //CASO 1: caso o início (cabeça) da lista está vazia
    if (isEmpty(l))
    {
        l->head = createNode(key);
    }
    else
    {
        //CASO 2: percorrer a lista e inserir o item no final dela
    
        aux = l->head;

        while (aux->next != NULL)
        {
            aux = aux->next;
        }

        aux->next = createNode(key);
    }
}
