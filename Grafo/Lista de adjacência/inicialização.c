//A função recebe como parametro o número de vértices e retorna um vetor com n posições
//Cada posição do vetor é uma lista encadeada que representa as arestas
static List **startAdjacentList(int n)
{
    int i;
    List **l = (List **)malloc(n * sizeof(List *));

    for (i = 0; i < n; i++)
    {
        l[i] = (List *)malloc(sizeof(List));
        l[i]->head = NULL;
    }

    return l;
}

//Iniciar o grafo
static Graph *startGraph(int vertices)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->vertices = vertices;
    g->edges = 0;
    g->adjacentList = startAdjacentList(vertices);

    return g;
}

