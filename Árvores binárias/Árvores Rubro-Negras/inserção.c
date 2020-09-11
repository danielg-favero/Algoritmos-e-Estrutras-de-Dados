//Obter o nó tio do nó passado na função
static Node *getUncle(Node *tree)
{
    Node *uncle = NULL;

    if (tree != NULL && tree->father != NULL)
    {
        //prevenir que a função retorne o pai
        if (tree->father->father->left == tree->father)
        {
            uncle = tree->father->father->right;
        }
        else
        {
            uncle = tree->father->father->left;
        }
    }

    return uncle;
}

//Obter o nó avó do nó passado na função
static Node *getGrandpa(Node *tree)
{
    Node *grandpa = NULL;

    if (tree != NULL && tree->father != NULL)
    {
        grandpa = tree->father->father;
    }

    return grandpa;
}

//Realizar rotação a direita
static Node *rotateRight(Node *tree)
{
    Node *father = tree->father;
    Node *grandpa = father->father;

    grandpa->left = father->right;
    father->right = grandpa;
    if (grandpa->father != NULL)
    {
        if (grandpa->father->left == grandpa)
            grandpa->father->left = father;
        else
        {
            grandpa->father->right = father;
        }
    }

    father->father = grandpa->father;
    grandpa->father = father;

    return father;
}

//Realizar rotação a esquerda
static Node *rotateLeft(Node *tree)
{
    Node *father = tree->father;
    Node *grandpa = father->father;

    grandpa->right = father->left;
    father->left = grandpa;
    if (grandpa->father != NULL)
    {
        if (grandpa->father->right == grandpa)
            grandpa->father->right = father;
        else
        {
            grandpa->father->left = father;
        }
    }

    father->father = grandpa->father;
    grandpa->father = father;

    return father;
}

//Realizar rotação dupla a direita
static Node *rotateDoubleRight(Node *tree)
{
    Node *father = tree->father;
    Node *grandpa = father->father;

    father->left = tree->right;
    tree->right = father;

    //atualizar o nó filho do avô
    if (grandpa->left == father)
        grandpa->left = tree;
    else
    {
        grandpa->right = tree;
    }

    tree->father = father->father;
    father->father = tree;

    //realizar uma rotação a esquerda após
    return rotateLeft(father);
}

//Realizar rotação dupla a esquerda
static Node *rotateDoubleLeft(Node *tree)
{
    Node *father = tree->father;
    Node *grandpa = father->father;

    father->right = tree->left;
    tree->left = father;

    //atualizar o nó filho do avô
    if (grandpa->left == father)
        grandpa->left = tree;
    else
    {
        grandpa->right = tree;
    }
    tree->father = father->father;
    father->father = tree;

    //realizar uma rotação a direita após
    return rotateRight(father);
}

//Balancear a árvore
static Node *balance(Node *tree)
{
    Node *father, *uncle;

    //CASO 1: O nó raiz sempre será preto
    if (tree->father == NULL)
    {
        tree->color = 1;
    }
    else
    {
        father = tree->father;

        if (father->color == 0)
        {
            uncle = getUncle(tree);

            //CASO 2: O tio é vermelho
            if (uncle != NULL && uncle->color == 0)
            {
                //inverter as cores do pai e tio
                father->color = 1;
                uncle->color = 1;
                tree = getGrandpa(tree);

                //se o avô não for a raiz ele será vermelho
                if (tree->father != NULL)
                {
                    tree->color = 0;
                }
            }
            else //CASO 3: O tio é preto
            {
                if (father->left == tree)
                {
                    //CASO 3C: Dupla rotação a direita
                    if (father->father->right == father)
                    {
                        tree = rotateDoubleRight(tree);
                    }
                    else //CASO 3A: Rotação a direita
                    {
                        tree = rotateRight(tree);
                    }
                }
                else
                {
                    //CASO 3D: Dupla rotação a esquerda
                    if (father->father->left == father)
                    {
                        tree = rotateDoubleLeft(tree);
                    }
                    else //CASO 3A: rotação a esquerda
                    {
                        tree = rotateLeft(tree);
                    }
                }

                //Inverter as cores dos nós
                tree->color = 1;

                //prevenir acesso a nós nulos
                if (tree->left != NULL)
                {
                    tree->left->color = 0;
                }
                if (tree->right != NULL)
                {
                    tree->right->color = 0;
                }
            }
        }
    }

    return tree;
}

Node *insert(Node *tree, int key)
{
    Node *child, *father;

    //inserir o nó raiz
    if (tree == NULL)
    {
        tree = create();
        tree->color = 1;
        tree->key = key;
    }
    else
    {
        child = tree;
        father = tree;

        //percorrer a árvore para encontrar a posição do próximo nó
        //a posição de inserção se encontra onde o nó é nulo
        while (child != NULL)
        {
            father = child;

            if (key < father->key)
            {
                child = child->left;
            }
            else
            {
                child = child->right;
            }
        }

        child = create();
        child->color = 0;
        child->key = key;
        child->father = father;

        //definir posição do nó filho
        if (child->key < father->key)
        {
            father->left = child;
        }
        else
        {
            father->right = child;
        }

        //balancear a árvore enquanto houver dois nós vermelhos adjacentes e enquanto não for a raiz
        while (
            (child->father != NULL) &&
            (child->color == 0) &&
            (child->father->color == 0))
        {
            //sempre balancear baseado no nó que foi inserido
            child = balance(child);
        }

        //retornar o referencial da raiz para o topo da árvore
        while (child->father != NULL)
        {
            child = child->father;
        }

        return child;
    }

    return tree;
}
