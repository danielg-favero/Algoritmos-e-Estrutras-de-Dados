//verificar a existência de uma areste entre os vértices
static int existEdge(Graph *g, int v1, int v2)
{
    //Como o grafo não é direcional, podemos apenas procurar em uma só lista
    if (g != NULL && g->adjacentList[v1]->head != NULL)
    {
        //Usando funções auxiliares de lista encadeada para encontrar a posição do vértice na lista
        return searchNode(g->adjacentList[v1], v2);
    }

    return 0;
}

//Inserir uma aresta entre dois vértices
static void insertEdge(Graph *g, int v1, int v2)
{
    if (!existEdge(g, v1, v2))
    {
        insertNode(g->adjacentList[v1], v2);
        insertNode(g->adjacentList[v2], v1);
        g->edges++;
    }
}
