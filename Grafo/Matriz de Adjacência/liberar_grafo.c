//Liberar a memória de um grafo
static void freeGraph(Graph *g)
{
    if (g != NULL)
    {
        free(g->adjacentMatrix);
        free(g);
    }
}
