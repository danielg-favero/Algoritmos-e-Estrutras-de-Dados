//Alteração na struct dos grafos
//Foi adicionado um vetor "pais" para controlar os pais dos vértices durante a busca em largura
struct Graph
{
    int edges;    //número de arestas
    int vertices; //número de vertices;
    int *fathers;

    //lista de adjacência
    //ela mostra as arestas que conectam um vértice a outro
    //Sua estrutura é de uma de uma matriz esparsa
    List **adjacentList;
};

//Algoritmo de busca em largura
void breadthFirstSearch(Graph *g, int origin)
{
    int i;
    Queue *q = createQueue();
    Node *currentVertex;
    Node *aux;

    g->fathers = malloc(g->vertices * sizeof(int));

    //ter controle dos vértices que foram visitados
    //0 para vértice que não foi visitado
    //1 para vértice que foi visitado mas possui vizinhos que não foram visitados
    //2 para vértice que foi visitado e não possui vizinho que não foi visitado
    int visited[g->vertices];

    //quantidade de passos do vértice de origem até outro vértice
    int distances[g->vertices];

    for (i = 0; i < g->vertices; i++)
    {
        visited[i] = 0;          //Nenhum vértice foi visitado
        distances[i] = INFINITY; //Como não sabemos a distância entre os vértices, consideramos elas infinitas
        g->fathers[i] = -1;      //Nenhum vértice possui pai por enquanto
    }

    //Marcar a origem como visitada e sua distância como 0
    visited[origin] = 1;
    distances[origin] = 0;

    //enfileirar o nó visitado
    enqueue(q, origin);

    //percorrer todo o grafo a partir do ponto de origem
    while (!queueIsEmpty(q))
    {
        //desenfileirar os vértices
        currentVertex = dequeue(q);
        aux = g->adjacentList[currentVertex->key]->head;

        //percorrer a lista de adjacência
        while (aux != NULL)
        {
            //verificar se o vértice já foi visitado
            if (visited[aux->key] == 0)
            {
                visited[aux->key] = 1;                                   //Mudar o vértice para visitado
                distances[aux->key] = distances[currentVertex->key] + 1; //aumentar a distância
                g->fathers[aux->key] = currentVertex->key;               //armazenar o vértice anterior como vértice pai do vértice atual
                enqueue(q, aux->key);                                    //Enfileirar o novo vértice
            }
            aux = aux->next;
        }

        //após percorrer a lista de adjacência, todos os nós adjacentes foram visitados
        visited[currentVertex->key] = 2;
    }
}
