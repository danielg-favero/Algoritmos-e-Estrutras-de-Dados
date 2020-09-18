//É preciso incluir a biblioteca stdbool.h para utilizar variáveis booleanas

//algoritmo de busca binária para árvores B
//Como cada página é ordenada, é possível realizar essa busca
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

//A pesquisa em uma árvore B é a mesma que um vetor normal
//Qualquer algoritmo de busca em vetor é correto aplicar nesse caso
static bool search(Node *root, int key)
{
    Node *tmp;
    int pos; //posição retornada pelo busca binária

    if (root != NULL)
    {
        tmp = root;

        while (tmp != NULL)
        {
            pos = binarySearchBTree(tmp, key);

            //Verificar se a posição é valida e se o valor foi encontrado
            if (pos < tmp->numberOfKeys && tmp->keys[pos] == key)
            {
                return true;
            }

            //percorrer os filhos da página
            tmp = tmp->children[pos];
        }
    }
    return false;
}
