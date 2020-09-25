//imprimir as arestas de um grafo não direcionado
//para evitar impressão de duas arestas iguais, como (a, b) e (b, a), será impresso apenas uma vez
void printEdges(Graph *g)
{
    int i, j;

    if (g != NULL)
    {
        for (i = 1; i < g->vertices; i++)
        {
            for (j = 0; j < i; j++)
            {
                if (g->adjacentMatrix[i][j] == 1)
                {
                    printf("(%d, %d)\t", i, j);
                }
            }
        }
    }
}
