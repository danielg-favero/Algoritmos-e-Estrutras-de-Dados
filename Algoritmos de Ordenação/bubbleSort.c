#include <stdio.h>

// O bubble-sort é um algoritmo simples de ordenação, percorremos o vetor
// encontrando o maior valor e colocando-o no fim do vetor
// O algoritmo percorre o vetor analisando os valores aos pares e realizando trocas
// de posição caso seja necessário.
// Sua complexidade é O(n) para o melhor caso (vetor já ordenado) e O(n²) no pior caso (vetor ordenado na ordem inversa)
// O algoritmo recebe um vetor de inteiros e o tamanho do vetor armazenado na variável n

void bubbleSort (int vet[], int n){
    int i; // contador do primeiro laço for
    int j; // contador do segundo laço for
    int aux; // variável auxiliar para fazer as trocas de posições

    // O primeiro laço conta quantas vezes o vetor foi percorrido
    
    for(i = 0; i < n; i++){

        // O segundo laço for faz as trocas de posições, começamos a contagem pelo primeiro valor e comparamos aos pares
        // entre o valor atual e o proximo, por esta razão, a repetição vai até o penultimo valor. Além disso, como teremos
        // o maior valor na ultima casa, não é necessario ordená-la novamente, então fazemos (n - 1 - i) repetições ao invés de 
        // (n - 1) a fim de não realizar operações desnecessárias.

        for(j = 0; j < n - 1 - i ; j++){
            
            // Caso o próximo valor seja menor, trocamos as posições
            if(vet[j] > vet[j + 1]){
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}
