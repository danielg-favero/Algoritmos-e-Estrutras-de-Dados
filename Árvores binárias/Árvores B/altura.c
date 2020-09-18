//Função que calcula a altura de uma árvore B
int bTreeHeight(Node *tree)
{
    //Como a árvore tem a mesma altura em todos os caminhos, é preciso percorrer apenas 1
    if (tree->children[0] != NULL)
    {
        return 1 + bTreeHeight(tree->children[0]);
    }

    return 0;
}
