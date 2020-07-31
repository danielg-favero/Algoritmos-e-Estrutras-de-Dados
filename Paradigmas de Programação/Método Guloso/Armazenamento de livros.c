#include <stdio.h>
#include <stdlib.h>

//      PROBLEMAS       //
/*
Dado um conjunto de livros numerados de 1 a n, sendo que o i-ésimo livro tem peso 0<p[i]≤10.  Implemente um algoritmo guloso para definir a quantidade mínima de envelopes seguindo as seguintes restrições:  cada envelope deve ter ≤ 2livros e o peso do conteúdo de cada envelope deve ser ≤10. Em seguida, faça a análise de complexidade da solução.
*/

//A função recebe um conjunto de pesos dos livros ordenados em ordem crescente
int armazenarLivros(int *p, int n){
    int c = 10; //Capacidade de cada envelope
    int nE = 0; //nº de envelopes
    int i = 0;
    
    //executar enquanto não percorrer todo vetor
    while(i < n){
        //Verificar a ultima posição do vetor onde não tem memória alocada em seguida
        //Caso o conjunto for ímpar
        if(i+1 < n){
            //verificar se é possível armazenar dois livros subsequentes
            if(p[i] + p[i+1] <= c){
                i++;
            }
        }
        //Em toda iteração um novo envelope é adicionado
        nE++;
        i++;
    }

    return nE;
}
