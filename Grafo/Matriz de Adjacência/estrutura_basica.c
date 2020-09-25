//Estrutra de um grafo representada por matriz de adjacência

struct Graph
{
    int edges;    //número de arestas
    int vertices; //número de vertices;

    //matriz de adjacência
    //ela mostrara 1 na posição (i, j) caso haja uma aresta que conect o vértice i ao j
    int **adjacentMatrix;
};
