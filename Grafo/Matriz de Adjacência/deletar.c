//Deletar a aresta que conecta v1 a v2
static void deleteEdge(Graph *g, int v1, int v2)
{
    if (g != NULL && existEdge(g, v1, v2))
    {
        g->adjacentMatrix[v1][v2] = 0;
        g->adjacentMatrix[v2][v1] = 0;
        g->edges--;
    }
}
