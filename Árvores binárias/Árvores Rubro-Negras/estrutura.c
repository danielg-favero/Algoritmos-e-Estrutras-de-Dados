typedef struct Node Node;

struct Node
{
    int key;
    int color;
    //bit que define a cor do nó
    //1 para preto
    //0 para vermelho

    Node *father;
    //Uma árvore rubro-negra tem um ponteiro adicional que aponta para o pai

    Node *left;
    Node *right;
};
