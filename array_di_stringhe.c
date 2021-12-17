/*
Scrivere un programma che chieda all’utente di inserire N parole. Il numero di parole viene richiesto all’utente. 
Il programma permette all’utente di:
ordinare le parole in ordine alfabetico
Stampare le parole
Cercare una parola

*/

#include <stdio.h>
#include <string.h>

#define MAX 11

void stampaTutti(char array[][100], int cont);
void ordingaParole(char array[][100], int cont);
int cercaParola(char array[][100], int cont, char parola[], int *pos);

int main(int argc, const char * argv[]) {
    char array[20][100];
    int n,i;
    int r;
    int posizione;
    
    printf("Inserisci quante parole vuoi: ");
    scanf("%d",&n);
    for (i=0; i<n; i++)
    {
        printf("Inserisci al stinga numero %d: ",i+1);
        scanf("%s",array[i]);
    }
    stampaTutti(array, n);
    if (cercaParola(array, n, "pippo", &posizione) == 1)
        printf("la parola è stata tovata in posizione %d\n", posizione);
    else
        printf("Parola non trovata\n");
    return 0;
}

void stampaTutti(char array[][100], int cont){
    for (int i=0; i<cont; i++)
    {
        printf("Stringa %d: %s\n",i+1,array[i]);
        
    }
}

int cercaParola(char array[][100], int cont, char parola[], int *pos){
    int i;
    *pos = -1;
    for (i=0; i<cont; i++){
        if (strcmp(array[i],parola)==0){
            *pos = i;
            return 1;
        }
    }
    return 0;
}
