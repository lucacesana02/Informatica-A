/*Si ipotizzi di volere scrivere un programma semplificato di Turtle Graphics.

Nel Turtle Graphics un disegnatore (detto anche tartaruga) viene posto inizialmente al centro di una matrice di caratteri di dimensione 101x101. Nella casella di partenza viene posto il carattere ‘x’, mentre in tutte le altre caselle della matrice viene posto il carattere ‘_’. All’inizio la tartaruga sta “guardando” verso l’alto.

La tartaruga è in grado di eseguire le seguenti operazioni:

Avanti: in questo caso la tartaruga si muove di una casella in avanti, nella direzione in cui sta “guardando”. Giunta nella nuova casella scrive il carattere ‘x’.
Destra: in questo caso la tartaruga ruota in senso orario di 90 gradi con il fine di “guardare in una nuova direzione”. Questa operazione non altera in alcun modo il contenuto della matrice.
Sinistra: in questo caso la tartaruga ruota in senso antiorario di 90 gradi, nuovamente con il fine di “guardare in una nuova direzione”. Anche questa operazione non altera in alcun modo il contenuto della matrice.

Implementare la seguente funzione:

int disegna(char matrice [101][101], char istruzione[100]);

Questa funzione riceve in ingresso la matrice iniziale in cui tutti i caratteri sono già posti a ‘_’, tranne il carattere al centro della matrice che invece è posto a ‘x’.

Riceve, inoltre, un array di al massimo 100 caratteri chiamato istruzione. L’array in questione contiene al suo interno una sequenza di istruzioni che la tartaruga dovrà compiere, codificate usando caratteri. Le istruzioni sono considerate finite quando si incontra un ‘\0’.

Il carattere ‘a’ indica un’operazione di Avanti.
Il carattere ‘d’ indica un’operazione di Destra.
Il carattere ’s’ indica un’operazione di Sinistra.

La funzione restituisce -1 se non è possibile realizzare il disegno richiesto, ovvero se cercando di eseguire il disegno la tartaruga finirebbe fuori dalla matrice. La funzione restituisce 1 se invece è possibile realizzare il disegno. Inoltre, in questo secondo caso, realizza il disegno secondo le istruzioni date, ovvero modifica la matrice cambiando alcuni dei suoi caratteri da ‘_’ in ‘x’.

N.B. Non è necessario scrivere il codice di inizializzazione della matrice, e neanche il codice di inizializzazione dell’array istruzione. Sono ricevuti come parametri in ingresso alla funzione e sono già “pieni”.
*/

#include <stdio.h>
#include <string.h>

#define MAX 11

int disegna(char matrice[MAX][MAX], char istruzione[25]);
void svuotaDisegno(char matrice[MAX][MAX]);
void stampa(char matrice[MAX][MAX]);

 int main(int argc, const char * argv[]) {
    char matrice[MAX][MAX];
    char istruzioni[25];
    
    svuotaDisegno(matrice);
    printf("Scrivi qui le istruzioni per la tartaruga: ");
    scanf(" %s",istruzioni);
    
    if (disegna(matrice, istruzioni)== 1){
        stampa(matrice);
    } else {
        printf("La tartaruga virtuale è morta\n");
    }
    return 0;
}
int disegna(char matrice[MAX][MAX], char istruzione[25]){
    char dir = 'u';
    int posX = MAX/2;
    int posY = MAX/2;

    int i;
    for (i=0; i<strlen(istruzione); i++){
        switch(istruzione[i]){
            case 'a':
                switch(dir){
                    case 'u':
                        if (posY==(MAX-1))
                            return -1;
                        else
                            posY++;
                        break;
                    case 'd':
                        if (posY==0)
                            return -1;
                        else
                            posY--;
                        break;
                    case 'l':
                        if (posX==0)
                            return -1;
                        else
                            posX--;
                        break;
                    case 'r':
                        if (posX==(MAX-1))
                            return -1;
                        else
                            posX++;
                        break;
                }
                matrice[posY][posX] = 'x';
                break;
            case 'd':
                switch(dir){
                    case 'u':
                        dir = 'r';
                        break;
                    case 'd':
                        dir = 'l';
                        break;
                    case 'l':
                        dir = 'u';
                        break;
                    case 'r':
                        dir = 'd';
                        break;
                }
                break;
            case 's':
                switch(dir){
                    case 'u':
                        dir = 'l';
                        break;
                    case 'd':
                        dir = 'r';
                        break;
                    case 'l':
                        dir = 'd';
                        break;
                    case 'r':
                        dir = 'u';
                        break;
                }
                break;
        }
    }
    return 1;
}

void svuotaDisegno(char matrice[MAX][MAX]){
    int i,j;
    for (i=0; i<MAX; i++){
        for (j=0; j<MAX; j++){
            matrice[i][j] = '_';
        }
    }
    matrice[MAX/2][MAX/2] = 'x';
    
}

void stampa(char matrice[MAX][MAX]){
    int i,j;
    for (i=MAX-1; i>=0; i--){
        for (j=0; j<MAX-1; j++){
            if (matrice[i][j]!='_')
                printf("x");
            else
                printf("_");
        }
        printf("\n");
    }
}
