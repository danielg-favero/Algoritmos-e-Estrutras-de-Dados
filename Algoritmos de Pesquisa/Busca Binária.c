//a função recebe um vetor ordenado
//ini == posição de inicio do vetor
//fim == posição de término do vetor
int busca_binaria(int *v, int ini, int fim, int valor)
{
    //executar a função enquanto o fim for maior que o inicio
    if (fim >= ini) { 
        int meio = ini + (fim - ini) / 2; 

        //caso base quando for encontrado o valor 
        if (v[meio] == valor) 
            return meio; 

        //caso o calor esteja da metade para cima do vetor
        if (v[meio] > valor)
            //chamada recursiva para a metade de baixo do vetor
            return busca_binaria(v, ini, meio - 1, valor); 

        //caso o valor esteja na metade para baixo do vetor
        return busca_binaria(v, meio + 1, fim, valor); 
    } 
    
    //caso não for encontrado o valor
    return -1; 
}
