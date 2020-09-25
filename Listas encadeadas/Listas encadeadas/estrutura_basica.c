//Estrutura básica para uma lista encadeada simples

typedef struct Node Node;
typedef struct List List;

struct Node
{
    int key;
    Node *next;
};

struct List
{
    Node *head;
};
