//Imprimir a lista de adjacência inteira
void printAdjacentList(Graph *g)
{
    int i;
    Node *aux;

    if (g != NULL)
    {
        for (i = 0; i < g->vertices; i++)
        {
            aux = g->adjacentList[i]->head;

            printf("%d ", i);
            while (aux != NULL)
            {
                printf("%d ", aux->key);
                aux = aux->next;
            }

            printf("\n");
        }
    }
}
