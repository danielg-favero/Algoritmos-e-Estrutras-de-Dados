
//Imprimir as arestas que conectam os vértices
void printEdges(Graph *g)
{
    int i;
    Node *aux;

    if (g != NULL)
    {
        for (i = 0; i < g->vertices; i++)
        {
            aux = g->adjacentList[i]->head;

            while (aux != NULL)
            {
                printf("(%d, %d)\n", i, aux->key);
                aux = aux->next;
            }
        }
    }
}
