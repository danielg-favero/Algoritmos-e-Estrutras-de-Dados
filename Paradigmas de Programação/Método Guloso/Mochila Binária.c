#include <stdio.h>
#include <stdlib.h>

//      PROBLEMA        //
/*
Dado uma mochila com capacidade C e um conjunto O = {a_1, a_2, ..., a_n} de objetos de determinado peso e valor. Selecionar um sub-conjunto S de objetos que caibam dentro da mochila de forma que o valor total dos objetos seja maximizado
*/

//A função recebe as sequência ordenadas pela razão valor/peso
int mochila(int *v, int *p, int n, int c)
{
    int valor = 0;
    int i;

    for (i = 0; i < n && p[i] <= c; i++)
    {
        c -= p[i];
        valor += v[i];
    }

    return valor;
}
