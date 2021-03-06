#include <stdio.h>
#define N 100

void creaMatrice(int matrix[][2*N-1], int n);
void stampaMatrice(int matrix[][2*N-1], int n);

int main(int argc, const char * argv[]) {
    int triangoloTartaglia[N][2*N-1];
    int n;
    
    printf("Inserisi il numero di righe del triangolo di tartaglia: ");
    scanf("%d",&n);
    
    creaMatrice(triangoloTartaglia,n);
    stampaMatrice(triangoloTartaglia,n);
    
    return 0;
    
}

void creaMatrice(int matrix[][2*N-1], int n){
    int i,j;
    
    //annullare tutta la matricina
    for (i=0; i<n; i++){
        for (j=0; j<=(2*(n-1)); j++){
            matrix[i][j] = 0;
        }
    }
    matrix[0][n-1] = 1;
    matrix[n-1][0] = 1;
    matrix[n-1][2*(n-1)] = 1;
    
    for (i=1; i<n; i++){
        for (j=1; j<(2*(n-1)); j++){
            matrix[i][j] = matrix[i-1][j-1] + matrix[i-1][j+1];
        }
    }
}

void stampaMatrice(int matrix[][2*N-1], int n){
    int i,j;
    for (i=0; i<n; i++){
        for (j=0; j<=(2*(n-1)); j++){
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}
