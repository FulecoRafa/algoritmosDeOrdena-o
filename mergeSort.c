#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define numOfPlayers 8

typedef struct _player{
    int id;
    int score;
}player;

void trocaPlayer(player* p1 , player* p2){
    player aux;
    aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

void merge(player* p, int ini, int meio, int fim){
    int i, j, k;
    int n1 = meio - ini + 1;
    int n2 =  fim - meio;
 
    player* I = (player*) malloc(sizeof(player)*n1); //vetor auxiliar da esquerda
    player* F = (player*) malloc(sizeof(player)*n2); //vetor auxiliar da direita
 
    for (i = 0; i < n1; i++){ //atribui os valores aos vetores
        I[i].id = p[ini + i].id;
        I[i].score = p[ini + i].score;
    }
    for (j = 0; j < n2; j++){
        F[j].id = p[meio + 1+ j].id;
        F[j].score = p[meio + 1+ j].score;
    }
 
    i = 0;
    j = 0;
    k = ini;
    while (i < n1 && j < n2){ //compara qual dos dois é maior e atribui ao vetor que os originou em ordem
        if (I[i].score <= F[j].score){
            p[k].score = I[i].score;
            p[k].id = I[i].id;
            i++;
        }
        else{
            p[k].score = F[j].score;
            p[k].id = F[j].id;
            j++;
        }
        k++;
    }
 
    while (i < n1){ //atribui os elementos que faltaram do vetor da esquerda
        p[k].score = I[i].score;
        p[k].id = I[i].id;
        i++;
        k++;
    }
 
    while (j < n2){ //atribui os elementos que faltaram do vetor da direita
        p[k].score = F[j].score;
        p[k].id = F[j].id;
        j++;
        k++;
    }
}

void mergesort(player* p, int ini, int fim)
{
    if (ini < fim) //quando inicio = fim o vetor tem apenas um elemento, desta forma atingindo a condiçãode parada
    {
        int meio = ini+(fim-ini)/2; //encontra a metade de cada recursão
 
        mergesort(p, ini, meio); //metade da esquerda
        mergesort(p, meio+1, fim); //metade da direita
 
        merge(p, ini, meio, fim);
    }
}

void alteraScore(char resultado, player *carinha){
    switch(resultado){
        case'D':
            carinha->score-=1;
            break;
        case'E':
            carinha->score+=1;
            break;
        case'V':
            carinha->score+=3;
            break;
    }
}

void printScoreBoard(player* p){
    printf("+----------------------+\n");
    for (int i = numOfPlayers - 1 ; i >= 0 ; i--){
        printf("|ID = %d ; Pontuação = %d|\n" , p[i].id , p[i].score);
    }
    printf("+----------------------+\n\n");
}
int main(void){
    clock_t begin , end;
    double tempero;
    player p[numOfPlayers] = {0};
    for(int i = 0 ; i < numOfPlayers ; i++){
        p[i].id = (i+1);
        p[i].score = 0;
    }
    printScoreBoard(p);
    printf("\n");
    while(1){
        int aux;
        printf("ID do jogador: ");
        scanf(" %d" , &aux);
        if(aux > 0 && aux <= 8){
            for(int i = 0 ; i < numOfPlayers ; i++){
                if(aux == p[i].id){
                    char resul;
                    printf("\nV para vitória ; E para empate ; D para derrota: ");
                    scanf(" %c" , &resul);
                    alteraScore(resul , &p[i]);
                    begin = clock();
                    mergesort(p,0,numOfPlayers-1);
                    end = clock();
                    tempero = ((double)(end - begin)/CLOCKS_PER_SEC*1.0);
                    printf("Tempo de ordenação: %lf" , tempero);
                    printf("\n");
                    printScoreBoard(p);
                    break;
                }
            }
        }else{
            break;
        }
    }
    printScoreBoard(p);
    return 0;
}
