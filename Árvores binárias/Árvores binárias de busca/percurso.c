//3 MANEIRAS DIFERENTES DE FAZER A IMPRESSÃO DAS INFORMAÇÕES DE UMA ÁRVORE BINÁRIA

//impressão do percurso de maneira pré-fixa
void prefixPrint(Node *tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->key);
        prefixPrint(tree->left);
        prefixPrint(tree->right);
    }
}

//impressão do percurso de maneira infixa
void infixPrint(Node *tree)
{
    if (tree != NULL)
    {
        infixPrint(tree->left);
        printf("%d ", tree->key);
        infixPrint(tree->right);
    }
}

//impressão do percurso de maneira sufixa
void posfixPrint(Node *tree)
{
    if (tree != NULL)
    {
        posfixPrint(tree->left);
        posfixPrint(tree->right);
        printf("%d ", tree->key);
    }
}
