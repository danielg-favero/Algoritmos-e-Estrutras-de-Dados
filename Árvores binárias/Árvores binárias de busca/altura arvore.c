int treeHeight(Node *tree){
    int leftHeight;
    int rightHeight;

    if(tree != NULL){
        //percorrer os dois ramos da árvore e comparar suas alturas
        leftHeight = 1 + treeHeight(tree->left);
        rightHeight = 1 + treeHeight(tree->right);

        //comparar as alturas dois dois ramos e retornar o valor ao nó pai
        if(leftHeight>rightHeight){
            return leftHeight;
        } else {
            return rightHeight;
        }

        return 1;
    }
    return 0;
}
