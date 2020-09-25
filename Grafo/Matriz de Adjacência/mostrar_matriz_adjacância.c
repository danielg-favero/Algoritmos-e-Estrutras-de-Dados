//imprimir matriz de adjacência
void printAdjacentMatrix(Graph *g)
{
    int i, j;

    if (g != NULL)
    {
        for (i = 0; i < g->vertices; i++)
        {
            for (j = 0; j < g->vertices; j++)
            {
                printf("%d ", g->adjacentMatrix[i][j]);
            }
            printf("\n");
        }
    }
}
