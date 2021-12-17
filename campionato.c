
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef enum {
    portiere = 1,
    difensore,
    centrocampista,
    attacante
} TipoRuolo;

typedef struct Giocatore {
    int numero;
    int goal;
    TipoRuolo ruolo;
} Giocatore;

int inserisciGiocatore(Giocatore g[], int i);
void contaGoal(Giocatore g[], int i, int *goalFatti, int *goalSubiti, int *goalAtt, int *goalCentro, int *goalDif);
Giocatore trovaMigliorGiocatore(Giocatore g[], int i);

int main(int argc, const char * argv[]) {
    Giocatore giocatori[MAX];
    int numGiocatori = 0;
    int totaleGoalFatti = 0;
    int totaleGoalSubiti = 0;
    int goalAttaccanti = 0;
    int goalDifensori = 0;
    int goalCentrocampisti = 0;
    
    Giocatore bestPlayer;
    int r;
    
    do{
        printf("MENU\n");
        printf("1) Inserisci nuovo giocatore\n");
        printf("2) Calcola goal\n");
        printf("3) Trova miglior giocatore\n");
        printf("4) ESCI\n");
        scanf("%d",&r);
        
        switch (r) {
            case 1:
                numGiocatori = inserisciGiocatore(giocatori, numGiocatori);
                break;
            case 2:
                contaGoal(giocatori, numGiocatori, &totaleGoalFatti, &totaleGoalSubiti, &goalAttaccanti , &goalCentrocampisti, &goalDifensori);
                printf("Goal fatti: %d\nGoal subiti: %d\nGoal attaccanti: %d\nGoal centrocampisti: %d\nGoal Difensori: %d\n",totaleGoalFatti, totaleGoalSubiti, goalAttaccanti, goalCentrocampisti, goalDifensori);
                break;
            case 3:
                bestPlayer = trovaMigliorGiocatore(giocatori, numGiocatori);
                printf("Numero giocatore %d\n",bestPlayer.numero);
                break;
            case 4:
                printf("Ciao!!!\n");
                break;
                
            default:
                printf("Operazione non valida\n");
                break;
        }
    }while(r!=4);
    return 0;
}

int inserisciGiocatore(Giocatore g[], int i){
    if (i<MAX){
        printf("Inserisci numero:");
        scanf("%d",&g[i].numero);
        printf("Inserisci goal:");
        scanf("%d",&g[i].goal);
        do{
            printf("Inserisci ruolo (%d: portiere, %d: difensore, %d: centrocampista, %d: attaccante",portiere,difensore,centrocampista,attacante);
        
            scanf("%d",&g[i].ruolo);
        }while(g[i].ruolo>4 || g[i].ruolo<1);
        return i+1;
    }
    else{
        printf("Lunghezza massima dell'array raggiunta");
        return i;
    }
}

void contaGoal(Giocatore g[], int i, int *goalFatti, int *goalSubiti, int *goalAtt, int *goalCentro, int *goalDif){
    
    *goalFatti = 0;
    *goalSubiti = 0;
    *goalDif = 0;
    *goalCentro = 0;
    *goalAtt = 0;
    int k;
    
    for (k=0; k<i; k++){
        switch (g[k].ruolo) {
            case portiere:
                *goalSubiti = *goalSubiti + g[k].goal;
                break;
            case difensore:
                *goalDif = *goalDif + g[k].goal;
                break;
            case centrocampista:
                *goalCentro = *goalCentro + g[k].goal;
                break;
            case attacante:
                *goalAtt = *goalAtt + g[k].goal;
                break;
        }
    }
    *goalFatti = *goalAtt + *goalCentro + *goalDif;
}

Giocatore trovaMigliorGiocatore(Giocatore g[], int i){
    Giocatore best;
    int k;
    
    best.goal = -1;
    best.numero = 0;
    best.ruolo = -1;
    
    for (k=0; k<i; k++){
        if ((g[k].ruolo!=portiere) && (g[k].goal>best.goal))
            best = g[k];
    }
    return best;
}

Giocatore trovaMigliorGiocatore2(Giocatore g[], int i){
    int k;
    int posMiglioreGiocatore = -1;
    
    for (k=0; k<i; k++){
        if ((posMiglioreGiocatore==-1) && (g[k].ruolo!=portiere))
            posMiglioreGiocatore = k;
        else if ((g[k].ruolo!=portiere) && (g[k].goal>g[posMiglioreGiocatore].goal))
            posMiglioreGiocatore = k;
    }
    return g[posMiglioreGiocatore];
}
