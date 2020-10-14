//algoritmo para converter um grafo de lista de adjacência em matriz de adjacência
void convertALintoAM(GraphAL *ga, GraphAM *gm)
{
    Node *aux;
    int i, j;

    if (ga != NULL && gm != NULL)
    {
        for (i = 0; i < ga->vertices; i++)
        {
            aux = ga->adjacentList[i]->head;
            
            //percorrer as listas de adjacência e adicionar as arestas ao vértices na matriz de adjacência
            while (aux != NULL)
            {
                insertEdgeInAM(gm, i, aux->key);
                aux = aux->next;
            }
        }
    }
}
