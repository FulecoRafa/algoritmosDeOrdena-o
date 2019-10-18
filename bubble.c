#include <stdio.h>
int main(){
    bool ordenado;
    int aux;
    for (int i = 0 ; i < n ; i++){//organiza por linha
        ordenado = false;
        while (!ordenado){// repete até que passe pela linha e não haja nenhuma troca de posição  
            ordenado = true;//usado para verificar se houve alguma troca
            for (int j = 0 ; j < /*limite de repetições*/ ; j++){
                if (num[i][j] > num[i][j + 1]){
                    aux = num[i][j + 1];
                    num[i][j + 1] = num[i][j];
                    num[i][j] = aux;
                    ordenado = false;
                }
            }
        }
    }
    return 0;
}