int isAvl(Node *tree)
{
    int leftHeight, rightHeight;
    int heightDiff;

    if (tree != NULL)
    {
        //percorrer as sub-árvores
        if (!isAvl(tree->left))
        {
            return 0;
        }

        if (!isAvl(tree->right))
        {
            return 0;
        }

        //Calcular as alturas das sub-árvores
        leftHeight = treeHeight(tree->left);
        rightHeight = treeHeight(tree->right);

        heightDiff = abs(leftHeight - rightHeight);

        //uma árvore é balanceada se as diferenças nas alturas das sub-árvores não for maior que 1 (em módulo)
        if (heightDiff == 0 || heightDiff == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return 1;
}
