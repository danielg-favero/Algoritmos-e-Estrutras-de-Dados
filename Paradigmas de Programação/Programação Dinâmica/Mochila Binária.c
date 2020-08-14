//      PROBLEMA
/*
Considere n itens a serem levados para uma viagem, dentro de uma mochila de capacidade ƛ. Cada item x_j tem um peso p_j e um valor v_j. Implemente uma função, utilizando programação dinâmica, que calcule o valor máximo de objetos que podem ser carregados dentro da mochila.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//inserir os pesos e os valores dos itens
void inserirPesosValor(int *pesos, int *valores, int n){
    int i;
    
    printf("\ninforme o peso e o valor de cada item:\n");
    for(i = 0; i < n; i++){
        printf("%d)\n", i+1);
        printf("Peso: ");
        scanf("%d", &pesos[i]);
        printf("Valor: ");
        scanf("%d", &valores[i]);

        printf("\n");
    }
}

//algoritmo da mochila binária
int maiorCusto(int capacidade, int *pesos, int *valores, int n){
    int custos[capacidade+1][n+2];
    int valorArmazenado;
    int melhorCaso0; //baseado no melhor caso = 0
    int melhorCaso1; //baseado no melhor caso = 1
    int i, j;
    
    //iniciar a primeira colunas com as capacidades
    //iniciar a segunda coluna com 0
    for(i = 0; i <= capacidade; i++){
        custos[i][0] = i;
        custos[i][1] = 0;
    }
    
    //começar a preencher a tabela
    for(j = 2; j <= n+1;j++){
        for(i = 0; i <= capacidade; i++){
            //usando para calcular: f_k(b) = max {f_{k-1}(b), C_k+f_{k-1}(b-a_i)}
            //k = coluna da tabela
            //b = capacidade das submochilas
            //C = custo de cada item
            //a = peso de cada item

            melhorCaso0 = custos[i][j-1];

            if(i >= pesos[j-2]){
                melhorCaso1 = valores[j-2]+custos[i-pesos[j-2]][j-1];

                if(melhorCaso0 > melhorCaso1){
                    valorArmazenado = melhorCaso0;
                } else {
                    valorArmazenado = melhorCaso1;
                }
            } else {
                valorArmazenado = melhorCaso0;
            }
            custos[i][j] = valorArmazenado;
        }
    }
    
    //retornar a posição de interesse
    return custos[capacidade][n+1];
}

int main() {
    int capacidade;
    int nItems;
    int totalArmazenado;
    
    printf("Informe a capidade da mochila: ");
    scanf("%d", &capacidade);

    printf("Informe a quantidade de itens: ");
    scanf("%d", &nItems);
    
    int pesos[nItems];
    int valores[nItems];
    
    inserirPesosValor(pesos,valores, nItems);
    
    totalArmazenado = maiorCusto(capacidade, pesos, valores, nItems);
    printf("\nFoi possível armazenar R$%d\n\n", totalArmazenado);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}