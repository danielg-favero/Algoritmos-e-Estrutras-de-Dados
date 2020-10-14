#define N 5 //ordem da árvore (número máximo de nós por página)

typedef struct Node Node;

struct Node
{
    int order;         //ordem da árvore
    int keys[N - 1];   //Cada página de uma árvore B tem no máximo N-1 elementos
    int numberOfKeys;  //Ter controle do número de elementos por página
    Node *children[N]; //Cada página de uma árvore B tem no máximo N filhos
    bool isLeaf;       //Ter controle se a página é um nó folha
};
