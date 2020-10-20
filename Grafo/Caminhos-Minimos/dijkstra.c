#define INF 10000

//procurar a aresta que possui menor peso dentro da fila
static int findSmallestWeight(Queue *q, int *weights, int n)
{
    int minWeight = INF;
    int pos = -1;
    int i;

    if (!queueIsEmpty(q))
    {
        for (i = 0; i < n; i++)
        {
            if (isInQueue(q, i) && weights[i] < minWeight)
            {
                minWeight = weights[i];
                pos = i;
            }
        }
    }

    return pos;
}

//remover da lista de acordo com a prioridade definida
static int removeFromQueue(Queue *q, int *weights, int n)
{
    NodeQueue *current, *previous;
    int pos = findSmallestWeight(q, weights, n);
    int key;
    int i = 0;

    if (!queueIsEmpty(q) && pos != -1)
    {
        current = q->begin;
        previous = q->begin;

        //encontrar a posição para remover da fila
        while (current->key != pos)
        {
            previous = current;
            current = current->next;
        }

        if (previous == current)
        {
            q->begin = q->begin->next;
        }
        else
        {
            previous->next = current->next;
        }

        if (current != NULL)
        {
            key = current->key;
            free(current); // remover o nó da fila
            return key;
        }
    }

    return -1;
}

//tentativa de melhorar o caminho de um vértice até outro
static void relax(GraphAM *gm, int currentVertex, int adjacentVertex, int *distances, int *fathers)
{
    //caso a distância para chegar ao vértice adjacente for maior que a soma do peso do vértice atual com a distância para chegar ao vértice atual, quer dizer que o vértice adjacente pode ser melhorado
    if (distances[adjacentVertex] > distances[currentVertex] + gm->adjacentMatrix[currentVertex][adjacentVertex])
    {
        distances[adjacentVertex] = distances[currentVertex] + gm->adjacentMatrix[currentVertex][adjacentVertex];
        fathers[adjacentVertex] = currentVertex;
    }
}

//algoritmo de dijkstra para gerar uma árvore de caminhos mínimos a partir de um grafo representado por matriz de adjacência
//ela recebe um grafo representado por matriz de adjacência e um vértice origem
int *dijkstraAlgorithmForAM(GraphAM *gm, int source)
{
    if (gm == NULL)
    {
        return NULL;
    }

    //fila de prioridade para percorrer todos os vértices
    Queue *priorityQueue = createQueue();

    //converter o grafo para matriz de adjacência
    GraphAL *ga = startGraphAL(gm->vertices);
    convertDirectionalAMintoAL(gm, ga);
    printAdjacentList(ga);

    int i;
    int *fathers = malloc(gm->vertices * sizeof(int)); //vetor que conterá o pai de cada vértice após a finalização do algoritmo

    int distances[gm->vertices]; //distância (a partir do vértice de origem) que custa para chegar em cada vértice

    for (i = 0; i < gm->vertices; i++)
    {
        distances[i] = INF;
        fathers[i] = -1;
        enqueue(priorityQueue, i);
    }

    //a distância entre o vértice de origem e ele mesmo é 0
    distances[source] = 0;

    int currentVertex;      //vértice atual que está sendo analisado
    NodeList *adjacentList; // lista de adjacência do vértice atual
    //printf("%d\n", currentVertex);
    while (!queueIsEmpty(priorityQueue))
    {
        currentVertex = removeFromQueue(priorityQueue, distances, gm->vertices);
        adjacentList = ga->adjacentList[currentVertex]->head;

        while (adjacentList != NULL)
        {
            relax(gm, currentVertex, adjacentList->key, distances, fathers);
            adjacentList = adjacentList->next;
        }
    }

    return fathers;
}
