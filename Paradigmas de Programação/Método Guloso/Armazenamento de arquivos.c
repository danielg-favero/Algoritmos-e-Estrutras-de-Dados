#include <stdio.h>
#include <stdlib.h>

//      PROBLEMA        //
/*
Dado um grande número de arquivos digitais em um computador. Cada arquivo ocupa um certo número de KB. Deseja-se armazenar a maior quantidade de arquivos em                uma mídia comcapacidade C. O problema pode ser modelado na seguinte maneira: dados números naturais representando o tamanho dos arquivosA={a1, a2, ..., an} e um valor C. Deseja-se encontrar o maior subconjunto S que satisfaça a restrição max(∑ ai) ≤ C. Em seguida, faça a análise decomplexidade da solução.
*/

//Estrutura para armazenar o subconjunto S (Opcional)
typedef struct
{
    int *arqs;
    int n;
} ArquivosArmazenados;

//A função recebe um conjunto ordenado de forma crescente
ArquivosArmazenados *maxArmazenamento(int *arqs, int n, int c)
{
    //Alocar espaço na memória para a estrutra
    ArquivosArmazenados *subArqs = malloc(sizeof(ArquivosArmazenados));
    subArqs->arqs = malloc(sizeof(int));
    subArqs->n = 0;

    int i = 0;

    //Começar a armazenar os arquivos enquanto a houver capacidade
    //Continuar armazenando na mídia enquanto não for percorrido todo vetor e enquanto for possível armazenar os arquivos
    while (i < n && c - arqs[i] >= 0)
    {
        c -= arqs[i];
        subArqs->arqs = realloc(subArqs->arqs, sizeof(int)); //Realocar mais espaço de memória para os arquivos armazenados
        subArqs->arqs[i] = arqs[i];
        subArqs->n++;
        i++;
    }

    return subArqs;
}
