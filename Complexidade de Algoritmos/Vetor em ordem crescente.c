#include <stdio.h>
#include <stdlib.h>

//O pior caso seria quando o vetor está em ordem crescente mas a função continua verificando todas as entradas da sequência
//Algoritimo de complexidade O(n)
int isInAscendingOrder(int *v, int n){
    int i;
    int soma=0; //Soma para verificar se a sequẽncia é constante

    for(i = 0; i < n-1;i++){
        if(v[i] > v[i+1]){
            return 0;
        }
        soma+=v[i];
    }
    soma+=v[i];

    if(soma == v[0]*n){
        return -1;
    } else {
        return 1;
    }
}
