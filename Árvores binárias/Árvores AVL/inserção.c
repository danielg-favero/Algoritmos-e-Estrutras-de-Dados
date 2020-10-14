//Realizar rotação da direita
Node *rotateLeft(Node *tree)
{
    Node *child = tree->left, *child2;

    if (child->balancingFactor == 1)
    {
        //rotação Left-Left (LL)
        tree->left = child->right;
        child->right = tree;
        tree = child;
    }
    else
    {
        //rotação Left-Right (LR)
        child = tree->left;
        child2 = child->right;
        child->right = child2->left;
        child2->left = child;
        tree->left = child2->right;
        child2->right = tree;

        if (child2->balancingFactor == 1)
        {
            tree->balancingFactor = -1;
        }
        else
        {
            tree->balancingFactor = 0;
        }

        if (child2->balancingFactor == -1)
        {
            tree->balancingFactor = 1;
        }
        else
        {
            child->balancingFactor = 0;
        }

        tree = child2;
    }

    return tree;
}

//Realizar rotação a direita
Node *rotateRight(Node *tree)
{
    Node *child = tree->right, *child2;

    if (child->balancingFactor == -1)
    {
        //Rotação Right-Right (RR)
        tree->right = child->left;
        child->left = tree;
        tree = child;
    }
    else
    {
        //Rotação Right-Left (RL)
        child = tree->right;
        child2 = child->left;
        child->left = child2->right;
        child2->right = child;
        tree->right = child2->left;
        child2->left = tree;

        if (child2->balancingFactor == -1)
        {
            tree->balancingFactor = 1;
        }
        else
        {
            tree->balancingFactor = 0;
        }

        if (child2->balancingFactor == 1)
        {
            tree->balancingFactor = -1;
        }
        else
        {
            child->balancingFactor = 0;
        }

        tree = child2;
    }

    return tree;
}

Node *insert(Node *tree, int key, bool *grown)
{
    if (tree == NULL)
    {
        tree = create(key);
        *grown = true; //ter controle caso a árvore crescer
    }
    else if (key < tree->key)
    {
        tree->left = insert(tree->left, key, grown);

        if (*grown)
        {
            //verificar o fator de balanceamento
            switch (tree->balancingFactor)
            {
            case -1:
                tree->balancingFactor = 0;
                *grown = false;
                break; //árvore balanceada
            case 0:
                tree->balancingFactor = 1;
                break; //árvore balanceada
            case 1:
                tree = rotateLeft(tree);
                tree->balancingFactor = 0;
                *grown = false;
            }
        }
    }
    else if (key > tree->key)
    {
        tree->right = insert(tree->right, key, grown);

        if (*grown)
        {
            switch (tree->balancingFactor)
            {
            case 1:
                tree->balancingFactor = 0;
                *grown = false;
                break; //árvore balanceada
            case 0:
                tree->balancingFactor = -1;
                break; //árvore balanceada
            case -1:
                tree = rotateRight(tree);
                tree->balancingFactor = 0;
                *grown = false;
            }
        }
    }

    return tree;
}
