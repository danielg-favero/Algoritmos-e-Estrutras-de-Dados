//Imprimir percurso de uma árvore B
void printTree(Node *tree)
{
    int i;

    if (tree != NULL)
    {
        printf("\n");

        //Imprimir todos os valores do nó
        for (i = 0; i < tree->numberOfKeys; i++)
        {
            printf("%d\t", tree->keys[i]);
        }

        //Percorrer todos os nós filhos
        for (i = 0; i <= tree->numberOfKeys; i++)
        {
            printTree(tree->children[i]);
        }
    }
}
