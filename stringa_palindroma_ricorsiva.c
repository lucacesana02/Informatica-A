//Funzione per verificare se stringa palindroma
//itopinonavevanonipoti
//i topi non avevano nipoti

#include <stdio.h>
#include <string.h>

int palidroma_ite(char stringa[]);
int palidroma_ric(char stringa[], int i, int n);
int palidroma_ric2(char stringa[], int i, int n);

int main (){

    char stringa[100];
    printf("Inserisci la stringa: ");
    gets(stringa);
    //if (palidroma_ite(stringa)==1)
    if (palidroma_ric2(stringa,0,strlen(stringa)-1)==1)
        printf("La stringa è palindroma\n");
    else
        printf("La stringa NON è palindroma\n");
    return 0;
}

int palidroma_ite(char stringa[]){
    int i;
    int n = strlen(stringa);
    
    for (i=0; i<n; i++,n--){
        if (stringa[i]!=stringa[n-1])
            return 0;
    }
    return 1;
}

int palidroma_ric(char stringa[], int i, int n){
    if (i>n)
        return 1; //la stringa è polindroma
    /*
    if (stringa[i]!=stringa[n])
        return 0;
    return palidroma_ric(stringa, i+1, n-1);
     */
    if (stringa[i]==stringa[n])
        return palidroma_ric(stringa, i+1, n-1);
    else
        return 0;
    
}

int palidroma_ric2(char stringa[], int i, int n){
    if (i>n)
        return 1;
    else {
        if (stringa[i]==' ')
            return palidroma_ric2(stringa, i+1, n);
        if (stringa[n]==' ')
            return palidroma_ric2(stringa, i, n-1);
        if (stringa[i]!=stringa[n])
            return 0;
        else
            return palidroma_ric2(stringa, i+1, n-1);
    }
}
