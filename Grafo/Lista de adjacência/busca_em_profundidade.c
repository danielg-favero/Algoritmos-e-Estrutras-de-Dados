static void visitALVertice(GraphAL *ga, int v)
{
    int i;
    Node *aux;

    //o vértice foi visitado
    ga->visited[v] = 1;

    if (!isEmpty(ga->adjacentList[v]))
    {
        aux = ga->adjacentList[v]->head;

        //percorrer os vértices adjacentes
        while (aux != NULL)
        {
            if (ga->visited[aux->key] == 0)
            {
                ga->fathers[aux->key] = v;
                visitALVertice(ga, aux->key);
            }

            aux = aux->next;
        }

        //todos os vértices adjacentes foram visitados
        ga->visited[v] = 2;
    }
}

//Algoritmo de busca em profundidade
void deepFirstSearchForAL(GraphAL *ga)
{
    int i;

    //vetor para verificar se um vértice foi visitado ou não
    //0 para os vértices não visitados
    //1 para os vértices visitados porém com vizinhos a serem visitados
    //2 para os vértices visitados e sem vizinhos a serem visitados
    ga->visited = malloc(ga->vertices * sizeof(int));

    //vetor para ter controle dos pais de cada vértice visitado
    ga->fathers = malloc(ga->vertices * sizeof(int));

    //iniciar o vetor de pais dos vértices e visitados
    for (i = 0; i < ga->vertices; i++)
    {
        ga->visited[i] = 0;
        ga->fathers[i] = -1;
    }

    for (i = 0; i < ga->vertices; i++)
    {
        if (ga->visited[i] = 0)
        {
            //começar a visitar todos os vértice do grafo
            visitALVertice(ga, i);
        }
    }
}
