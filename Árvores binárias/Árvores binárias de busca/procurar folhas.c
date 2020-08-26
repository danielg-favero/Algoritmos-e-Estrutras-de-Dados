void findLeaf(Node *tree){
    if(tree != NULL){
        //percorrer os dois ramos da árvore
        findLeaf(tree->left);
        findLeaf(tree->right);
        
        //um nó é uma folha se não possuir filhos
        if(tree->left == NULL && tree->right == NULL){
            printf("%d", tree->key);
        }
    }
}
