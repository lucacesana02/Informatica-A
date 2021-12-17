/* Programma numeri complessi
 obiettivo: ordinare in ordine crescente per modulo
 Ideare una struttura dati per il numero complesso
 Ideare l'algoritmo di ordinamento
 Scrivere il programma nel modo più modulare (con tanti sottoprogrammi) possibile
 */

#include <stdio.h>
#include <math.h>

#define MAX 10

struct complesso {
    float re;
    float im;
};

void inserisci(struct complesso *c);
float modulo(struct complesso *c);
void ordina(struct complesso *c_in, struct complesso *c_out, int n);
int compara (struct complesso *c1, struct complesso *c2);

int main(int argc, const char * argv[]) {
    struct complesso array_sorgente[MAX];
    struct complesso array_destinazione[MAX];
    int n,i;
    
    printf("Quanti valori vuoi inserire?");
    scanf("%d",&n);
    for (i=0; i<n; i++){
        //inserisci(&array_sorgente[i]);
        inserisci(array_sorgente+i);
    }
    ordina(array_sorgente, array_destinazione, n);
    for (i=0; i<n; i++){
        printf("(%.2f %.2f) modulo: %.2f\n",array_destinazione[i].re,array_destinazione[i].im, modulo(array_destinazione+i));
    }
    printf("\n");
    return 0;
}

void inserisci(struct complesso *c){
    printf("Parte reale: ");
    scanf("%f",&(c->re));
    printf("Parte immaginaria: ");
    scanf("%f,",&(*c).im);   // (*c). == c->
}

float modulo(struct complesso *c){
    return sqrt(((*c).re * c->re) + ((*c).im * c->im));
}

void ordina(struct complesso *c_in, struct complesso *c_out, int n){
    struct complesso temp;
    int i, scambio;
    
    //Copia l'array d'ingresso in quello di uscita
    for (i=0; i<n; i++)
        c_out[i] = c_in[i];
    
    do{
        scambio = 0;
        for (i=0; i<n-1; i++){
            if (compara(&c_out[i], c_out+i+1) > 0){
                temp = c_out[i];
                *(c_out+i) = c_out[i+1];
                c_out[i+1] = temp;
                scambio = 1;
            }
        }
    }while(scambio);
}

int compara (struct complesso *c1, struct complesso *c2){
    if (modulo(c1) > modulo(c2))
        return 1;
    else if (modulo(c1)< modulo(c2))
        return -1;
    else
        return 0;
}

