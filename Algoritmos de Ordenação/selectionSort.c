#include <stdio.h>

// O selection sort é um algoritmo de ordenação simples que encontra o maior valor / menor valor
// e o depois o coloca na posição correta.
// Sua complexidade é O(n²) para o melhor caso, médio e pior casos, visto que sempre percorremos
// o vetor para encontrar a posição do maior valor
// A função recebe um vetor e o seu tamanho

void selectionSort (int vet[], int n){

    int i; // contador do primeiro laço for
    int j; // contador do segundo laço for
    int pos; // indice da posição do maior valor
    int aux; // variável auxiliar para as trocas

    // O primeiro laço for conta quantas vezes o vetor foi percorrido
    for(i = 0; i < n; i++){
        
        // A maior posição recebe o último valor não ordenado, para que possamos reduzir a quantidade de repetições
        pos = n - i;

        // O segundo laço for percorre o vetor até o penúltimo valor não ordenado e troca o valor da variável pos
        // caso encontre um valor maior 

        for(j = 0; j < n - 1 - i; j++){
            if(vet[j] > vet[pos]){
                pos = j;
            }
        }

        // No fim, trocamos de posição o último valor não ordenado com a posição de maior valor
        aux = vet[n - i];
        vet[n - i] = vet[pos];
        vet[pos] = aux;

        // Também podemos fazer a troca de posição sem utilizar variáveis auxiliares
        // vet[n - i] += vet[pos];
        // vet[pos] = vet[n - i] - vet[pos];
        // vet[n - 1] -= vet[pos];
    }
}
