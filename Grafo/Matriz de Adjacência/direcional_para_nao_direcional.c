//função para tornar um grafo direcionado em um não direcionado
void directionalToNonDirectional(GraphAM *g)
{
    int i, j;

    if (g != NULL)
    {
        for (i = 0; i < g->vertices; i++)
        {
            for (j = 0; j < g->vertices; j++)
            {
                //se existe uma aresta que conecta dois vértices, tornar os dois adjacentes
                if (existEdge(g, i, j))
                {
                    g->adjacentMatrix[i][j] = 1;
                    g->adjacentMatrix[j][i] = 1;
                }
            }
        }
    }
}
