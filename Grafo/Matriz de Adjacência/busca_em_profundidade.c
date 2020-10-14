static void visitAMVertex(GraphAM *gm, int v)
{
    int i, j;

    //o vértice foi visitado
    gm->visited[v] = 1;

    //percorrer os vértices adjacentes
    for (i = v; i < gm->vertices; i++)
    {
        for (j = 0; j < gm->vertices; j++)
        {
            if (existEdgeInAM(gm, i, j))
            {
                if (gm->visited[j] == 0)
                {
                    gm->fathers[j] = v;
                    visitAMVertex(gm, j);
                }
            }
        }
    }

    //todos os vértices adjacentes foram visitados
    gm->visited[v] = 2;
}

//Algoritmo de busca em profundidade
void deepFirstSearchForAM(GraphAM *gm)
{
    int i;

    //vetor para verificar se um vértice foi visitado ou não
    //0 para os vértices não visitados
    //1 para os vértices visitados porém com vizinhos a serem visitados
    //2 para os vértices visitados e sem vizinhos a serem visitados
    gm->visited = malloc(gm->vertices * sizeof(int));

    //vetor para ter controle dos pais de cada vértice visitado
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
            //começar a visitar todos os vértice do grafo
            visitAMVertex(gm, i);
        }
    }
}
