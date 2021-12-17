/*
 Scrivere un programma che continui a leggere delle stringhe (di lunghezza massima 20 caratteri). Il totale delle stringhe da leggere non è definito a priori e l'allocazione deve occupare meno memoria possibile. Ad ogni lettura viene chiesto all'utente se vuole continuare ad inserire o meno. Alla fine dell'inserimento il programma stampa nell'ordine inverso le stringhe inserite. Scrivere una seconda funzione che presa in ingresso una stringa, la stampi al contrario.
 */

#include <stdio.h>
#include <stdlib.h>
#define N 20

int inserisci(char *stringa[]);
void stampa(char *string[], int i);
void stampaParola(char parola[]);

int main(){
    char *stringa[N];
    int num = 0;
    
    num = inserisci(stringa);
    stampa(stringa, num);
    return 0;
}

int inserisci(char *stringa[]){
    int n = 0;
    int sizeSingleString = sizeof(char)*N;
    char r;
    do {
        stringa[n] = (char *)malloc(sizeSingleString);
        printf("Inserisci la parola: ");
        scanf(" %s",stringa[n]);
        n++;
        printf("Vuoi inserire un'altra strigna?^ (s/n) ");
        scanf(" %c",&r);
    } while(r=='s');
    return n;
}

void stampa(char *stringa[], int i){
    for (i=i-1; i>=0; i--){
        stampaParola(stringa[i]);
    }
}

void stampaParola(char parola[]){
    char *i;
    int len = 0;
    for (i=parola; *i!='\0'; i++)
        len++;
    for (i=parola+len-1; i>=parola; i--)
        printf("%c",*i);
    printf("\n");
}
