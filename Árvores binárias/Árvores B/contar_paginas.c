//Função estática para contar a quantidade de nós em uma árvore B tirando sua raiz
static int nodeCounter(Node *tree)
{
    int counter = 0;
    int i;
    if (tree != NULL)
    {
        //Percorrer todos os itens do nó e seus respectivos filhos
        for (i = 0; i <= tree->numberOfKeys; i++)
        {
            //Não aumentar o contador se os nós forem nulos
            if (tree->children[i] != NULL)
            {
                counter += 1 + nodeCounter(tree->children[i]);
            }
        }
    }
    return counter;
}

//Função que une a quantidade de nós com o nó raiz
int pageCounter(Node *tree)
{
    return 1 + nodeCounter(tree);
}
