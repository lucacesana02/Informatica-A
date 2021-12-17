#include <stdio.h>
#include <string.h>
#define MAX 200

typedef struct voto{
    char nome[20];
    char cognome[20];
    int matricola;
    int valutazione;
}voto;

int inserisciVoto(voto classe[], int i);
int cercareStudente(voto classe[], int i, int matricola);
void stampaIstrogramma(voto classe[], int i);
int riempiBocciati(voto classe[], int i, voto bocc[]);
void stampa (voto a[], int i);

int main(){
    voto voti[MAX];
    voto bocciati[MAX];
    int numVoti = 0;
    int numBocciati = 0;
    int r;
    int matricola;
    int v;
    
    do {
        printf("1) Inserisci voto\n");
        printf("2) Cerca studente\n");
        printf("3) Istogramma\n");
        printf("4) Array bocciati\n");
        printf("5) ESCI\n\n");
        scanf("%d",&r);
        
        switch (r) {
            case 1:
                numVoti = inserisciVoto(voti, numVoti);
                stampa(voti,numVoti);
                break;
                
            case 2:
                printf("Inserisci matricola da cercare: ");
                scanf("%d",&matricola);
                v = cercareStudente(voti, numVoti, matricola);
                if (v!=-1)
                    printf("%s %s %d\n",voti[v].nome, voti[v].cognome, voti[v].valutazione);
                else
                    printf("Studente non trovato\n");
                break;
            
            case 3:
                stampaIstrogramma(voti, numVoti);
                break;
            case 4:
                numBocciati = riempiBocciati(voti, numVoti, bocciati);
                stampa(bocciati,numBocciati);
                break;
        }
    }while (r!=5);
    return 0;
    
}


int inserisciVoto(voto classe[], int i){
    printf("Inserisci nome: ");
    scanf("%s",classe[i].nome);
    printf("Inserici cognome: ");
    scanf("%s",&classe[i].cognome[0]);
    printf("Matricola: ");
    scanf("%d",&classe[i].matricola);
    printf("Voto: ");
    scanf("%d",&classe[i].valutazione);
    return i+1;
}

int cercareStudente(voto classe[], int i, int matricola){
    int k;
    for (k=0; k<i; k++){
        if (classe[k].matricola == matricola)
            return k;
    }
    return -1;
}

int cercareStudentePerCognome(voto classe[], int i, char cognome[]){
    int k;
    for (k=0; k<i; k++){
        if (strcmp(classe[k].cognome,cognome)==0)
            return k;
    }
    return -1;
}
void stampaIstrogramma(voto classe[], int i){
    int k,j,max = 0;
    int isto[5] = {0,0,0,0.0};
    for (k=0; k<i; k++){
        if (classe[k].valutazione<=6)
            isto[0]++;
        else if (classe[k].valutazione<=18)
            isto[1]++;
        else if (classe[k].valutazione<=25)
            isto[2]++;
        else if (classe[k].valutazione<=30)
            isto[3]++;
        else
            isto[4]++;
    }
    
    for (k=0; k<5; k++){
       if (isto[k]>max)
           max = isto[k];
    }
    
    for (k=max; k>0; k--){
        for(j=0; j<5; j++){
            if (isto[j]>=k)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int riempiBocciati(voto classe[], int i, voto bocc[]){
    int k;
    int num =0;
    for (k=0; k<i; k++){
        if (classe[k].valutazione<18){
            bocc[num] = classe[k];
            num++;
        }
    }
    return num;
}

void stampa (voto a[], int i){
    int k;
    for (k=0; k<i; k++){
        printf("%d %s %s %d\n",a[k].matricola,a[k].cognome,a[k].nome,a[k].valutazione);
    }
}
