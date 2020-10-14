//É PRECISO FUNÇÕES DE LISTA ENCADEADA PARA FUNCIONAR

int isDirectionalAL(GraphAL *ga)
{
    Node *aux;
    int i;

    for (i = 0; i < ga->vertices; i++)
    {
        aux = ga->adjacentList[i]->head;

        while (aux != NULL)
        {
            //continuar percorrendo enquanto houver os dois vértices forem adjacentes
            if (searchNode(ga->adjacentList[i], aux->key) && searchNode(ga->adjacentList[aux->key], i))
            {
                aux = aux->next;
            }
            else
            {
                //não foi encontrado um vértice na lista de adjcência do outro
                return 1;
            }
        }
    }

    return 0;
}
