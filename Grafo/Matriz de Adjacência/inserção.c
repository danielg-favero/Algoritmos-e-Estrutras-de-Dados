//validar se um vértice pode ser inserido no grafo ou se ele existe no grafo
static int validateVertice(Graph *g, int v)
{
    return (v >= 0) && (v <= g->vertices);
}

//verificar se já existe uma aresta que conecta v1 a v2
static int existEdge(Graph *g, int v1, int v2)
{
    return (g != NULL) && (validateVertice(g, v1)) && (validateVertice(g, v2)) && (g->adjacentMatrix[v1][v2] == 1);
}

//Inserir uma aresta que conecta v1 a v2
static void insertEdge(Graph *g, int v1, int v2)
{
    if (!existEdge(g, v1, v2))
    {
        g->adjacentMatrix[v1][v2] = 1;
        g->adjacentMatrix[v2][v1] = 1;
        g->edges++;
    }
}
