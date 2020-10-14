typedef struct Node Node;

//Estrutura básica de uma árvore
struct Node
{
    int key;
    
    //fator de balanceamento 
    //ele é definido como a diferença de altura da sub-árvore esquerda pela sub-árvore direita
    //todo nó possui um fator de balanceamento que será usado para balancear a árvore
    int balancingFactor;
    
    Node *left;
    Node *right;
};
