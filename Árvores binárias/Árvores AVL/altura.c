//Algoritmo para calcular a altura de uma árvore AVL
int treeHeight(Node *tree)
{
    int leftHeight, rightHeight;

    if (tree != NULL)
    {
        leftHeight = 1 + treeHeight(tree->left);
        rightHeight = 1 + treeHeight(tree->right);

        if (leftHeight > rightHeight)
        {
            return leftHeight;
        }
        else
        {
            return rightHeight;
        }

        return 1;
    }

    return 0;
}
