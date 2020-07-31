#include <stdio.h>
#include <stdlib.h>

//      PROBLEMA        //
/*
Dado conjunto de objetos S={a, b, c, d, e, f, g, h, i, j}, sendo cada com um determinadopeso e valor (p, v) e uma mochila com capacidade máxima de peso 22.  Para cada objeto, o peso e valor foram definidos da seguinte forma: a: (14,7), b: (3,6), c: (18,6), d: (5,5), e: (8,24), f: (6,10), g: (10,25), h: (4,16), i: (2,7), j: (5,14). Considerando o problema da mochila fracionária, qual é a solução ótima (melhor/maior custo benefício) para o armazenamento de objetos?
*/

//Ordenar os vetores pela razão valor / peso
void bubblesort(int *v, int *p, int n)
{
    int i, j, aux;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (v[j] / p[j] < v[j + 1] / p[j + 1])
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;

                aux = p[j];
                p[j] = p[j + 1];
                p[j + 1] = aux;
            }
        }
    }
}

//A função os objetos ordenados pela razão valor / peso
float mochila_fracionaria(int *p, int *v){
    int c = 22; //Capacidade da mochila definida no exercício
    int n = 10; //Nº de objetos definido no exercício
    float valorTotal = 0;
    int i;

    for(i = 0; i < n && c >= p[i]; i++){
        c -= p[i];
        valorTotal += v[i];
    }

    //Caso os objetos não tenham cabido na mochila, seu valor será fracionado
    if(c > 0 && i < n){
        valorTotal += (c/(float)p[i]) * v[i];
    }

    return valorTotal;
}

void mostrar_vetor(int *v, int n) {
    int i;

    for (i = 0; i < n; i++){
        printf("%d\t", v[i]);
    }
    printf("\n");
}

int main()
{
    //Valores padrão com o exercício
    int objetos[2][10]={
       {14, 3, 18, 5, 8, 6, 10, 4, 2, 5},
       { 7, 6,  6, 5,24,10, 25,16, 7,14}
    };

    bubblesort(objetos[1], objetos[0], 10);
    printf("Valor total armazenado: %.2f\n", mochila_fracionaria(objetos[0], objetos[1]));
}

