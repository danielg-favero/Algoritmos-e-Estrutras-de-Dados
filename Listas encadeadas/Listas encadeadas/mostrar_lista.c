//mostrar os itens de uma lista encadeada
void printList(List *l)
{
    Node *aux;

    if (!isEmpty(l))
    {
        aux = l->head;

        while (aux != NULL)
        {
            printf("%d\t", aux->key);
            aux = aux->next;
        }
    }
}
