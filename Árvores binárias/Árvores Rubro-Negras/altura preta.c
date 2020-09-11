//Calcular a altura preta de uma árvore
//Altura Preta: Quantidade nós pretos entre dois nós
int blackHeight(Node *tree)
{
    int height;

    if (tree != NULL)
    {
        //Como a árvore está sempre balanceada, é preciso percorrer apenas um nó
        height = tree->color + blackHeight(tree->left);

        return height;
    }

    return 0;
}
