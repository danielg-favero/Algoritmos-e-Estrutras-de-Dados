#include <stdio.h>
#include <stdlib.h>

// O insertion sort é um algoritmo de ordenação simples que percorre o vetor, inserindo os valores na posição correta
// Como em um jogo de cartas, conforme recebemos cada carta, colocamos ela na posição correta.
// Esse algoritmo percorre o vetor e a cada repetição, comparamos o valor com os indices ja percorridos, encontrando
// a posição correta nesse sub-vetor
// Este algoritmo tem complexidade O(n) para o melhor caso (vetor ordenado) e O(n²) para o pior caso (vetor inversamente ordenado)

void insertionSort(int vet[], int n){
    int i; // contador do primeiro laço for
    int j; // contador do segundo laço for
    int aux; // variável auxiliar para as trocas

    // Começamos a contagem pelo segundo valor, pois não é necessário ordenar um sub-vetor de apenas um valor
    for(i = 1; i < n; i++){
        
        // A variável auxiliar recebe o valor que queremos inserir
        // Precisamos desta variável, pois ao adiantar os valores, o valor no indice 'i' será substituído
        aux = vet[i];

        // Percorremos o sub-vetor até encontrar a posição correta
        // A cada vez que percorremos o vetor, adiantamos os valores uma posição a frente
        for(j = i - 1; j >= 0 && aux < vet[j]; j--){
            vet[j + 1] = vet[j];
        }

        // Por fim, inserimos o valor na posição correta
        // Obs.: é necessário utilizar j + 1 pois o for colocará o indice na posição anterior antes de 
        // encerrar as repetições
        vet[j + 1] = aux; 
    }
}
