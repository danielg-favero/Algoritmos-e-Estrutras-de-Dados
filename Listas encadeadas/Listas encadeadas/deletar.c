//algoritmo para deletar itens de uma lista encadeada
void deleteNode(List *l, int key)
{
    Node *aux, *before;

    if (!isEmpty(l))
    {
        aux = l->head;

        //CASO 1: O item a ser removido está na cabeça
        if (key == aux->key)
        {
            l->head = l->head->next;
        }
        else //CASO 2: O item a ser removido está no meio da lista
        {
            //ter controle do item que está antes daquele a ser removido
            before = aux;

            while (aux != NULL && aux->key != key)
            {
                before = aux;
                aux = aux->next;
            }

            //pular a posição do nó auxiliar para excluir o mesmo
            if (aux != NULL)
            {
                before->next = aux->next;
            }
        }

        if (aux != NULL)
        {
            free(aux);
        }
    }
}
