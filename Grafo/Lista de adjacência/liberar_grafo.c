//Liberar memória do grafo
static void freeGraph(Graph *g)
{
    int i;

    if (g != NULL)
    {
        for (i = 0; i < g->vertices; i++)
        {
            free(g->adjacentList[i]);
        }

        free(g);
    }
}
