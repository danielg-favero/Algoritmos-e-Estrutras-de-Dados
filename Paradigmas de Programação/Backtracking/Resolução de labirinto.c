#include <stdio.h>
#include <stdlib.h>

//      PROBLEMA
/*
    Dada uma matriz m x n que representa um labirinto, com (xi, yi) como posição inicial e (xf, yf) como posição final. Encontrar uma solução para esse labirinto usando backtracking
*/

//a função um labirinto m x n
//onde -1 é um possível cominho e -2 é parede
int resolverLabirinto(int m, int n, int lab[m][n], int li, int ci, int lf, int cf, int *movX, int *movY){
    int i;
    int c, l;
    int passos;

    //caso base: quando for encontrado uma solução
    if(li == lf && ci == cf){
        return lab[li][ci];
    }

    //testar todas as possibilidades de movimento nos 4 eixos
    for(i = 0; i < 4; i++){
        l = li + movY[i];
        c = ci + movX[i];

        if(
            l >= 0 &&
            l < m &&
            c >= 0 &&
            c < n &&
            lab[l][c] == -1    
        ){
            //atualizar o caminho já visitado para prevenir volta
            lab[l][c] = lab[li][ci] + 1;

            passos = resolverLabirinto(m, n, lab, l, c, lf, cf, movX, movY);

            if(passos > 0){
                return passos;
            }
        }
    }

    //caso não tenha encontrado uma solução
    return 0;
}
