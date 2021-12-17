//Scrivere un programma che permetta di sommare un array di N valori interi.
//Scrivere il programma utilizzando gli array e poi solo i puntatori.

#include <stdio.h>
#include <stdlib.h>
#define N 5

void inserisci(int *);
int somma(int array[]);

int main(int argc, const char * argv[]) {
    int val[N];
    int *val;
    
    printf("Inserisci gli N=%d valori: ",N);
    inserisci(val);
    printf("La somma dei numeri inseriti vale: %d\n", somma(val));
    return 0;
}*/

void inserisci(int *, int len);
int somma(int array[], int len);

int main(int argc, const char * argv[]) {
    int *val = NULL;
    int len = 0;
    int array[20];

    printf("Quanti valori vuoi inserire? ");
    scanf("%d",&len);
    
    val = (int *)malloc(sizeof(int)*len);
    printf("Inserisci gli N=%d valori: ",len);
    inserisci(val, len);
    printf("La somma dei numeri inseriti vale: %d\n", somma(val, len));
    return 0;
}

void inserisci(int array[], int len){
    int i;
    for (i=0; i<len; i++)
        scanf("%d",&array[i]);
}

void inserisci2(int *array, int len){
    int *start = array;
    while(array<start+len){
        scanf("%d",array);
        array++;
    }
}

int somma(int array[], int len){
    int i;
    int somma = 0;
    for (i=0; i<len; i++){
        somma = somma + array[i];
    }
    return somma;
}

int somma2(int *array, int len){
    int somma = 0;
    int *i;
    
    for (i=array; i<array+len; i++)
        somma = somma + *i;
    return somma;
}
