void convertAMintoAL(GraphAM *gm, GraphAL *ga)
{
    NodeList *aux;
    int i, j;

    if (gm != NULL)
    {
        for (i = 1; i < gm->vertices; i++)
        {
            //como o grafo não é direcionado é preciso apenas inserir uma aresta por par de vértices
            for (j = 0; j < i; j++)
            {
                if (gm->adjacentMatrix[i][j] > 0)
                {
                    insertEdgeInAL(ga, i, j);
                }
            }
        }
    }
}
