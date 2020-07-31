#include <stdio.h>
#include <stdlib.h>

//      PROBLEMA        //
/*
Dado um conjunto de horarios para a realização de atividades de uma sala de aula. Qual a melhor maneira de organizar esses horários que seja possível atender o maor número de atividades e sem que esses duas ou mais atividades tenham o mesmo horário na sala
*/

//A função recebe os horários ordeados por horário de término
int selecionar_atividades(int *ini, int *fim, int n){
    int qtde = 1; //Como está ordenado por ordem de término, o primeiro elemento sempre será selecionado
    int i;
    int j = 0;

    for(i = 0; i < n; i++){
        //Compara o início o início da atividade com o final da pŕoxima
        //Caso encontre, a atividade selecionada será o pivô de comparação
        if(ini[i] > fim[j]){
            j = i;
            qtde++;
        }
    }

    return qtde;
}
