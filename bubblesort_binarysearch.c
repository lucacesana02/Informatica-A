```c
#include <stdio.h>
#define MAX 10

void riempiArray(int array[]);
void stampaArray(int array[]);
void bubbleSort(int array[]);
int binarySearch(int array[], int x);

int main(int argc, const char * argv[]) {
    int a[] = {64, 34, 25, 12, 22, 11, 90, 13, 54, 77};
    int r, val;
    
    //printf("%d\n", sizeof(array)/sizeof(int));
    
    do{
        printf("MENU\n");
        printf("1) Inserisci nuovo array\n");
        printf("2) Ordina array\n");
        printf("3) Ricerca binaria in array\n");
        printf("4) Stampa array\n");
        printf("5) ESCI\n");
        scanf("%d",&r);
        
        switch(r){
            case 1:
                riempiArray(a);
                stampaArray(a);
                break;
            case 2:
                printf("Prima: ");
                stampaArray(a);
                bubbleSort(a);
                printf("Dopo: ");
                stampaArray(a);
                break;
            case 3:
                
                printf("Insersci il valore da carcare: ");
                scanf("%d",&val);
                if (binarySearch(a, val)==-1)
                    printf("Elemento non trovato\n");
                else
                    printf("Elemento trovato\n");
                break;
            case 4:
                stampaArray(a);
                break;
            case 5:
                printf("Arrivederci!!!\n");
                break;
            default:
                printf("Operazione non supportata\n");
                break;
        }
    }while(r!=5);
    
}

void stampaArray(int array[]){
    int i;
    for (i=0; i<MAX; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

void stampaArray2(int array[]){
    int i;
    for (i=0; i<MAX; i++){
        printf("%d ",*(array+i));
    }
    printf("\n");
}

void riempiArray(int array[]){
    int i;
    for (i=0; i<MAX; i++){
        //scanf("%d",&array[i]);
        scanf("%d",(array+i));
    }
}

void bubbleSortNoOpt(int array[]){
    int i, j, temp;
    for (i=0; i<MAX; i++){
        for (j=0; j<MAX-1; j++)
        {
            if (array[j]>array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1]=temp;
            }
        }
    }
}

void bubbleSort(int array[]){
    int i,j,temp;
    int swap = 0;
    
    //for (i=0; ((i<MAX) && (swap == 0)); i++){
    do{
        swap = 1;
        for (j=0; j<MAX-1; j++){
            if (array[j]>array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swap = 0;
            }
        }
        
    }while(swap == 0);
}

int binarySearch(int array[], int x){
    int inizio = 0;
    int fine = MAX-1;
    int medio;
    
    while(inizio<=fine){
        medio = inizio+(fine-inizio)/2;
        if (array[medio]==x)
            return medio;
        if (x>array[medio])
            inizio = medio+1;
        else
            fine = medio-1;
    }
    return -1;
}
```
