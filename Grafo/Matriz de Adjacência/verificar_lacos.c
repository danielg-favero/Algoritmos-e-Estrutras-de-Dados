//Algoritmo para verificar se o grafo possui laços
void verifyLoops(GraphAM *g)
{
    int i;

    for (i = 0; i < g->vertices; i++)
    {
        //Um laço ocorre quando há uma aresta que conecta um vértice nele mesmo
        if (existEdge(g, i, i))
        {
            printf("%d\n", i);
        }
    }
}
