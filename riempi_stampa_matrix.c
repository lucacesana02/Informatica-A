#include <stdio.h>
#define DIMX 100
#define DIMY 100

void stampa(char mat[][DIMY], int dx, int dy);

int main(int argc, const char * argv[]) {
    char matrice[DIMX][DIMY];
    int i,j;
    int dim;
    
    printf("Inserisci quante righe vuoi inserire: ");
    scanf("%d",&dim);
    
    for (i=0; i<dim; i++){
        for(j=0; j<dim; j++){
            scanf(" %c",&matrice[i][j]);
        }
    }
    stampa(matrice, dim, dim);
    return 0;
}

void stampa(char mat[][DIMY], int dx, int dy){
    int i,j;
    for (i=0; i<dx; i++){
        for(j=0; j<dy; j++){
            printf(" %c", mat[i][i]);
        }
        printf("\n");
    }
}
