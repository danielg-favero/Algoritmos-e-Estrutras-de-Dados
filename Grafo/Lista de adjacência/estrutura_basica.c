//Estrutura básica para uma grafo representado por lista de adjacência
//Essa estrutura requer uma lista encadeada simples para representar as arestas entre dois vértices

struct Graph
{
    int edges;    //número de arestas
    int vertices; //número de vertices;

    //lista de adjacência
    //ela mostra as arestas que conectam um vértice a outro
    //Sua estrutura é de uma de uma matriz esparsa
    List **adjacentList;
};
