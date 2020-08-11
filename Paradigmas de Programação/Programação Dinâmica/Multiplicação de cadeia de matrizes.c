//      PROBLEMA        
/*
    Dado um conjunto de matrizes M = {A(m x n), B(n x l), C(l x k)...}, Qual deve ser a ordem com que essas matrizes devem ser multiplicadas de modo a realizar menos operações?
*/

#include <stdio.h>
#include <stdlib.h>
#define INFINITY 100000

int minOperacoes(int *ordemMatrizes, int n){
    //matriz de custo minimo de operacoes
    int custoOperacoes[n-1][n-1];
    /*
        EX:
            1   2   3   4
        1   0
        2       0
        3           0
        4               0

        -> as linhas representam a partir de qual matriz começara a multiplicação
        -> nas posições onde i = j o custo é 0 pois uma matriz sozinha não realiza operacoes
        -> as colunas representam quantas matrizes vão ser multiplicadas
        -> nosso interesse está na posição (1,4), onde serão multiplicadas as quarto matrizes
    */

    //Ter controle da diagonal que estamos trabalhando
    int diagonal;
    int valorMininmo;
    int temp;
    int i, j, k;

    //iniciar a diagonal principal com zero
    for(i = 0; i < n - 1; i++)
        custoOperacoes[i][i] = 0;

    //percorrer a diagonal até se encontrar na posição do canto superior direito
    for(diagonal = 1; diagonal < n ;diagonal++){
        for(i = 1; i < n-diagonal; i++){
            j = i + diagonal;
            valorMininmo = INFINITY;

            //Para calcular o custo mínimo das diferentes possibilidades de permutações:
            //m[i, j] = min{m[i,k]+m[k+1,j]+d(i-1)*d(k)*d(j)}
            //-> m = Matriz de custo de operações
            //-> d = entradas do vetor das ordens da matriz
            for(k = i; k <= j-1; k++){
                temp = custoOperacoes[i-1][k-1] + custoOperacoes[k][j-1]+ordemMatrizes[i-1]*ordemMatrizes[k]*ordemMatrizes[j];

                if(temp<valorMininmo){
                    valorMininmo=temp;
                }
            }
            custoOperacoes[i-1][j-1] = valorMininmo;
        }
    }

    //retornar a posição do canto superior direito
    return custoOperacoes[0][n-2];
}

int main(){
    int numMatrizes;
    int *ordemMatrizes;
    int totalOperacoes;
    int i;

    printf("Informe a quantidade de matrizes: ");
    scanf("%d", &numMatrizes);

    //o vetor das matrizes vai armazenar as linhas da primeira matriz, as colunas da ultima matriz e o restante que está no meio
    //EX: m x n, n x l, l x k. Não há necessidade de armazenar duas vezes os valores de n e l
    ordemMatrizes = malloc((numMatrizes+1) * sizeof(int));

    printf("Informe o numero de linhas e colunas das matrizes:\n");
    for(i = 0; i <= numMatrizes; i++){
        printf("%d) ", i+1);
        scanf("%d", &ordemMatrizes[i]);
    }

    totalOperacoes = minOperacoes(ordemMatrizes, numMatrizes + 1);
    
    printf("\nSerao necessarios %d operacoes\n\n", totalOperacoes);
}
