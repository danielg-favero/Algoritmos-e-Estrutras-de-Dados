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

int main(){
    int *v; 
    int n;
    int i;
    int isAscending;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);

    v = malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        printf("%d: ", i + 1);
        scanf("%d", &v[i]);
    }

    isAscending = isInAscendingOrder(v, n);

    if(isAscending == 1){
        printf("\nO vetor está em ordem crescente!\n");
    } else if(isAscending == 0){
        printf("\nO vetor NÃO está em ordem crescente!\n");
    } else if(isAscending == -1){
        printf("\nA sequência é constante!\n");
    }
}