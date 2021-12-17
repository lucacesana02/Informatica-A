#include <stdio.h>
#include <string.h>
//Funzioni per calcolo della lunghezza di una stringa
int strlen_ite(char stringa[]);
int strlen_ric(char stringa[]);
int strlen_ric2(char stringa[], int i);

int main(){
    char stringa[100];
    printf("Insersici la stringa: ");
    //scanf(" %s",stringa);
    gets(stringa);
    
    printf("La lunghezza della stringa %s è %d\n",stringa,strlen_ite(stringa));
    printf("La lunghezza della stringa %s è %d\n",stringa,strlen_ric2(stringa,0));
}

int strlen_ite(char stringa[]){
    int len;
    for (len=0; stringa[len]!='\0'; len++);
    return len;
}

int strlen_ric(char *stringa){
    if (*stringa == '\0')
        return 0;
    return 1 + strlen_ric(++stringa);
}

int strlen_ric2(char stringa[], int i){
    if (stringa[i]=='\0')
        return 0;
    return 1 + strlen_ric2(stringa, i+1);
}
