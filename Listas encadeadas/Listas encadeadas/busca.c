//algoritmo para realizar buscas em uma lista encadeada
int searchNode(List *l, int key)
{
    Node *aux;

    if (!isEmpty(l))
    {
        aux = l->head;
        
        //percorrer enquanto a lista não for nula
        while (aux != NULL && aux->key != key)
        {
            aux = aux->next;
        }
      
        //verificar se o item foi encontrado ou se a pesquisa chegou ao final da lista
        if (aux != NULL && aux->key == key)
        {
            return 1;
        }
    }

    return 0;
}
