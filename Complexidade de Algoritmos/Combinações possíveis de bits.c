#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Algoritmo de complexidade O(2^n)
void printBitsSequence(int n){
    int seq[n];
    int i, j, k;
    int power = pow(2, n);

    //Uma sequência de n termos terá 2^n combinações possíveis
    for(i = 0; i < power; i++){
        k = i;
        //Começar a inserção dos bits de traz para frente na sequência, como aprendemos a calcular
        for(j = n-1; j >= 0; j--){
            seq[j] = k % 2;
            k = k / 2;
        }
        for(j = 0; j < n; j++){
            printf("%d", seq[j]);
        }
        printf("\n");
    }
}
