#include <stdio.h>
#include <stdlib.h>

// Função mergesort, divide o vetor em sub-vetores, até que o tamanho desses vetores seja 1.
// Depois, chama a função merge, que ordena os sub-vetores aos pares até que o vetor esteja 
// completamente ordenado.
// A função recebe um vetor, o indice do inicio do vetor e o indice do fim do vetor
// Este algoritmo tem complexidade O (nlgn) para todos os casos

// int v[] = vetor
// int l = inicio do vetor (indice esquerdo)
// int r = fim do vetor (indice direito)

void mergesort (int v[], int l, int r){
    int m; // indice do meio do vetor

    // Verificamos se o indíce inicial é menor que o final para garantir que a função não 
    // seja executada nos endereços de memória que não pertencem a cada sub-vetor
    if (l < r){

        // Atribuimos o valor do meio para ( l + r ) / 2
        // Nesse caso utilizamos ( l + (r - 1) ) / 2 para evitar overflow e chega ao mesmo
        // resultado

        m = (l + (r - 1)) / 2;

        // Chamadas recursivas da função mergesort que criam os sub-vetores
        // que começam no valor do primeiro indice até o indice do meio
        // e outro que começa no valor do meio + 1 até o fim do vetor

        mergesort(v, l, m);
        mergesort(v, m + 1, r);

        // Chamada da função merge, que ordena os sub-vetores
        merge(v, l, m, r); 
    }
}

void merge (int v[], int l, int m, int r){
    int i, j, k; // contadores auxiliares
    int nL = (m - l) + 1; // quantidade de numeros no vetor esquerdo
    int nR = r - m; // quantidade de numeros no vetor direito

    // Primeiramente, criamos dois vetores adicionais e inserimos os valores
    // dos sub-vetores ordenados
    
    int vetL[nL]; // vetor ordenado esquerdo
    int vetR[nR]; // vetor ordenado direito
    for(i = 0; i < nL;i++)
        vetL[i] = v[l + i];
    for(j = 0; j < nR; j++)
        vetR[j] = v[m + 1 + j];

    // Recopiamos os numeros dos vetores adicionais de volta para o vetor primario
    // de maneira ordenada

    i = 0; // contador do vetor esquerdo
    j = 0; // contador do vetor direito
    k = l; // contador do vetor primario

    while(i < nL && j < nR){
        if(vetL[i] <= vetR[j]){
            v[k] = vetL[i];
            i++;
        }
        else{
            v[k] = vetR[j];
            j++;
        }
        k++;
    }

    // Ao fim do primeiro while, ainda temos valores que não foram adicionados para o vetor primario
    // Por isso, temos que terminar de percorrer e adicionar os valores restantes em um dos dois vetores
    // adicionais.

    while(i < nL){
        v[k] = vetL[i];
        i++;
        k++;
    }
    
    while(j < nR){
        v[k] = vetR[j];
        j++;
        k++;
    }
}
