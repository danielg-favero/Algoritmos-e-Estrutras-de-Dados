static int findVertex(GraphAM *gm, int v)
{
    int i, j;
    int found = 0;

    //o vértice foi visitado
    gm->visited[v] = 1;

    //percorrer os vértices adjacentes
    for (i = v; i < gm->vertices; i++)
    {
        for (j = 0; j < gm->vertices; j++)
        {
            if (existEdgeInAM(gm, i, j))
            {
                //evitar que seja comparado a mesma aresta que foi percorrido anteriormente
                if (gm->fathers[v] != j)
                {
                    if (gm->visited[j] == 0)
                    {
                        gm->fathers[j] = v;
                        found = findVertex(gm, j);
                    }
                }
                else if (gm->visited[j] == 1) //o vértice foi encontrado
                {
                    return 1;
                }
            }
        }
    }
    //todos os vértices adjacentes foram visitados
    gm->visited[v] = 2;
    return found;
}

//algoritmo para verificar se um grafo é cíclico ou acíclico
int isCyclic(GraphAM *gm)
{
    //A estratégia é utilizar o algoritmo de busca em profundidade para encontrar um vértice visitado mas que possúi vizinhos para visitar. Caso isso ocorra o grafo é cíclico

    int i;
    int found = 0;

    //vetor para verificar se um vértice foi visitado ou não
    //0 para os vértices não visitados
    //1 para os vértices visitados porém com vizinhos a serem visitados
    //2 para os vértices visitados e sem vizinhos a serem visitados
    gm->visited = malloc(gm->vertices * sizeof(int));
    gm->fathers = malloc(gm->vertices * sizeof(int));

    //iniciar o vetor de pais dos vértices e visitados
    for (i = 0; i < gm->vertices; i++)
    {
        gm->visited[i] = 0;
        gm->fathers[i] = -1;
    }

    for (i = 0; i < gm->vertices; i++)
    {
        if (gm->visited[i] == 0)
        {
            found = findVertex(gm, i);
        }

        //vértice encontrado
        if (found)
        {
            return 1;
        }
    }

    //vértice não encontrado
    return 0;
}
