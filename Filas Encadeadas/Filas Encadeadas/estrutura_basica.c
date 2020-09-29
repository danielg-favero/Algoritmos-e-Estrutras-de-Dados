//Estrutura básica de uma fila encadeada

typedef struct Node Node;
typedef struct Queue Queue;

struct Node{
    int key;
    Node *next;
};

struct Queue
{
    Node *begin; //início da fila
    Node *end; //fim da fila
};
