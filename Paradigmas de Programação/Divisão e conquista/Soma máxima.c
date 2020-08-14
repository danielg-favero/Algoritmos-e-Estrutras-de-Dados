
//      PROBLEMA
/*
Dado um vetor de inteiros. Implemente uma função, utilizando divisão e conquista, que encontre a soma máxima no vetor. Por exemplo: para o vetor v = {-1, 3, 0, -2, 1, 3, -4, 5}, a soma máxima é 13 (3 + 0 + 1 + 3 + 5).
*/

//a função recebe um vetor com números quaisquer, o inicio e o fim dele
int somaMaxima(int *v, int ini, int fim){
    int meio;
    
    //3 casos bases
    //quando o inicio < 0
    //quando o inicio > fim
    //quando inicio == fim
    if(ini < 0|| ini > fim){
        return 0;
    } else if(ini == fim){
        if(v[ini] >= 0){
            return v[ini];
        }
    } else {
        //dividir o vetor ao meio
        meio = (ini+fim) / 2;
        
        //2 casos
        //quando o meio for positivo
        //quando o meio for negativo
        if(v[meio] >= 0){
            return v[meio] + somaMaxima(v, ini, meio-1) + somaMaxima(v, meio + 1, fim);
        } else {
            return somaMaxima(v, ini, meio-1) + somaMaxima(v, meio + 1, fim);
        }
    }

    return 0;
}
