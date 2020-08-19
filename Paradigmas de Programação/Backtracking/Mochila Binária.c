//    PROBLEMA
/*
  Considere n itens a serem levados para uma viagem, dentro de uma mochila de capacidade c. Cada item x_j tem um peso p_j e um valor v_j. Implemente uma função, utilizando backtracking, que calcule o valor máximo de objetos que podem ser carregados dentro da mochila.
*/

int mochilaBinaria(int c, int ini, int fim, int *pesos, int *valores){
    //ramo onde o nó deve ser adicionado
    int com = 0;

    //ramo onde o nó não deve ser adicionado
    int sem;

    if(ini >= fim){
        return 0;
    } else {
        //ramo esquerdo: soma-se o valor dos nós
        if(pesos[ini] <= c){
            com = pesos[ini] + mochilaBinaria(c - pesos[ini], ini+1, fim, pesos, valores);
        }

        //ramo direito: não soma o valor dos nós
        sem = mochilaBinaria(c, ini+1, fim, pesos, valores);

        //retornar o ramo que possui melhor resultado
        if(com > sem){
            return com;
        } else {
            return sem;
        }
    }
}
