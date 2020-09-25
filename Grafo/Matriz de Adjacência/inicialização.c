//funções para inicialização de grafos representados por matriz de adjacência

//a função que inicia a matriz de adjacência recebe como parâmetro o número de vértices (nós)
//a matriz de adjacência é uma matriz n x n
static int **startAdjacentMatrix(int n)
{
    int i, j;
    int **matrix = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    //iniciar todas as posições com 0
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

//a função recebe o número de vértices que o grafo terá
Graph *startGraph(int vertices)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->vertices = vertices;
    g->edges = 0;
    g->adjacentMatrix = startAdjacentMatrix(vertices);

    return g;
}
