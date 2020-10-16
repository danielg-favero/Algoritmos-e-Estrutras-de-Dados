#define INF 10000

/*
O ALGORITMO DE PRIM GERA UMA ÁRVORE Á PARTIR DE UM GRAFO PONDERADO CUJA CUSTO DE PERCURSO É O MÍNIMO
*/

//procurar a aresta que possui menor peso dentro da fila
static int findSmallestWeight(Queue *q, int *weights, int n)
{
    int minWeight = weights[0];
    int pos = 0;
    int i;

    if (!queueIsEmpty(q))
    {
        for (i = 1; i < n; i++)
        {
            //validar apenas os vértices que estejam na fila
            if (isInQueue(q, i) && weights[i] < minWeight)
            {
                minWeight = weights[i];
                pos = i;
            }
        }
        return pos;
    }

    return -1;
}

//remover da lista de acordo com a prioridade definida
static int removeFromQueue(Queue *q, int *weights, int n)
{
    NodeQueue *current, *previous;
    int pos = findSmallestWeight(q, weights, n);
    int key;
    int i = 0;

    if (!queueIsEmpty(q))
    {
        current = q->begin;
        if (pos == 0)
        {
            q->begin = q->begin->next;
        }
        else
        {
            //encontrar a posição para remover da fila
            for (i = 0; i < pos && current != NULL; i++)
            {
                previous = current;
                current = current->next;
            }
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

//algoritmo de Prim para gerar uma árvore de caminho mínimo em grafos ponderados
int *primsAlgorithmForAM(GraphAM *gm, int root)
{
    Queue *priorityQueue = createQueue();
    NodeList *adjacentList;
    int currentVertex;
    int i;

    //convertar para grafo representado por matriz de adjacẽncia
    GraphAL *ga = startGraphAL(gm->vertices);
    convertAMintoAL(gm, ga);

    //vetor para ter controle dos pesos mínimos
    int weights[gm->vertices];

    //arvore mínima a ser gerada
    int tree[gm->vertices];

    for (i = 0; i < gm->vertices; i++)
    {
        weights[i] = INF;          // iniciar todos os pesos com infinito
        tree[i] = -1;              // iniciar todos os pais dos vértices com -1 (não possuem pais)
        enqueue(priorityQueue, i); // enfileirar todos os vértices para contruir a árvore
    }

    // raiz da árvore
    weights[0] = root;

    //construir a árvore enquanto a fila não estiver vazia
    while (!queueIsEmpty(priorityQueue))
    {
        //desenfileirar e encontrar o vértice que possua a menor peso nas arestas
        //esse vértice deve estar adjacente a árvore
        i = removeFromQueue(priorityQueue, weights, gm->vertices);
        adjacentList = ga->adjacentList[i]->head;

        //percorrer toda a lista de adjacência do vértice para atualizar as informações de pai e pesos
        while (adjacentList != NULL)
        {
            currentVertex = adjacentList->key;

            if (isInQueue(priorityQueue, adjacentList->key) && gm->adjacentMatrix[i][currentVertex] < weights[currentVertex])
            {
                tree[currentVertex] = i;
                weights[currentVertex] = gm->adjacentMatrix[i][currentVertex];
            }

            adjacentList = adjacentList->next;
        }
    }

    return tree;
}
