//É preciso incluir a biblioteca math.h para algumas funções matemáticas utilizadas e stdbool.h e para usar variáveis booleanas

static int binarySearchBTree(Node *page, int key)
{
    int middle, begin, end;
    begin = 0;
    end = page->numberOfKeys - 1;

    while (begin <= end)
    {
        middle = (begin + end) / 2;

        if (page->keys[middle] == key)
        {
            return middle; //resultado encontrado
        }
        else if (page->keys[middle] < key)
        {
            begin = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }

    //O resultado não foi encontrado
    //Ele irá:
    // - Retonar a posição para o próximo filho da página
    // - Ou retorna a posição para ser inserido um novo item

    return begin;
}

//Função para dividir uma página cheia em duas, deve ser executada antes da inserção de uma chave
static Node *splitPage(Node *father, int fullPos)
{
    int i;

    Node *leftPage = father->children[fullPos]; //as (N-1)/2 menores chaves pertecem a essa página

    Node *rightPage = create();           //as (N-1)/2 maiores chaves pertecem a essa página
    rightPage->isLeaf = leftPage->isLeaf; //Se a página divida for uma folha, então as novas páginas vão ser folhas também

    //arredondar sempre para o inteiro mais proximo
    rightPage->numberOfKeys = round((N - 1) / 2);

    //preencher a página a direita com os (N-1)/2 maiores itens da página cheia
    for (i = 0; i < rightPage->numberOfKeys; i++)
    {
        rightPage->keys[i] = leftPage->keys[i + rightPage->numberOfKeys];
    }

    //Se as página direita não for folha, ele deve herdar os filhos do respectivos itens
    //Usando a página esquerda para comparar pois ela é quem controla toda a operação
    if (!leftPage->isLeaf)
    {
        for (i = 0; i < rightPage->numberOfKeys; i++)
        {
            rightPage->children[i] = leftPage->children[i + rightPage->numberOfKeys];
        }
    }

    //após a atribuiçao dos herdeiros para a página direita, a página esquerda deve reduzir seu tamanho
    leftPage->numberOfKeys = (N - 1) / 2;

    //Atualizar a página pai, inserindo a chave que foi promovida
    //Se a página pai tiver diversos itens nela, é preciso encontrar o item que apontará para página direita

    for (i = father->numberOfKeys + 1; i > fullPos + 1; i--)
    {
        father->children[i + 1] = father->children[i];
    }

    //Unir o pai a seus dois filhos
    father->children[fullPos + 1] = rightPage;
    father->children[fullPos] = leftPage;

    //Promover a primeira chave da página direita, que passará a dividir a página direita da esquerda
    //No caso é a primeira da página direita pois tivemos que mover ela para essa página anteriormente
    father->keys[fullPos] = rightPage->keys[0];
    father->numberOfKeys++;

    //remover o primeiro elemento da página direita
    for (i = 0; i < rightPage->numberOfKeys; i++)
    {
        rightPage->keys[i] = rightPage->keys[i + 1];
    }
    rightPage->numberOfKeys--;

    return father;
}

//Função para inserir itens em uma página não cheia
static Node *insertInNonFullPage(Node *tree, int key)
{
    int i;

    //Encontrar a posição que o item deve ser inserido
    int pos = binarySearchBTree(tree, key);

    //Caso uma nó seja folha é presumido que ele não esteja cheio
    if (tree->isLeaf)
    {
        //fazer o deslocamento dos itens na página para inserir na ordem correta
        for (i = tree->numberOfKeys; i > pos; i--)
        {
            tree->keys[i] = tree->keys[i - 1];
        }

        tree->keys[i] = key;
        tree->numberOfKeys++;
    }
    else
    {
        //Caso a página não seja folha e esteja cheia
        if (tree->children[pos]->numberOfKeys == N - 1)
        {
            tree = splitPage(tree, pos);

            //aumentar o valor da posição para ser percorrido no próximo filho
            if (key > tree->keys[pos])
            {
                pos++;
            }
        }

        //continuar percorrendo para encontrar um local para inserir o item
        tree = insertInNonFullPage(tree->children[pos], key);
    }

    return tree;
}

Node *insert(Node *tree, int key)
{
    Node *tmp = tree;
    Node *newPage;

    //Se a raiz estiver cheia ela deve ser dividida e uma chave deve ser promovida
    //Se a raiz estiver cheia, sua altura deve aumentar e ela deve ser repartida

    //Caso a árvore estiver cheia:
    if (tmp->numberOfKeys == N - 1)
    {
        newPage = create();         //criar a nova página que é nó promovido
        newPage->isLeaf = false;    //um nó que é promovido nunca é folha
        newPage->children[0] = tmp; // o primeiro filho a esquerda do nó é a antiga raiz
        tree = splitPage(newPage, 0);

        newPage = insertInNonFullPage(newPage, key); //Agora que a página não está mais cheia é possível inserir nela
    }
    else
    {
        //inserir normalmente
        tmp = insertInNonFullPage(tmp, key);
    }

    return tree;
}
