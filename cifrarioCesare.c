```c
#include <stdio.h>
#define MAX 100

void cifrarioCesare(unsigned char stringa[], unsigned char key, int cifra);
void copiaStringa(char str1[], char str2[]);
void inizializza(int list[], int n, int inValue);

int main(int argc, const char * argv[]) {
    unsigned char str[MAX];
    unsigned char oldStr[MAX];
    unsigned char c;
    unsigned char i;
    int lista[MAX];

    printf("Inserisci la parola da cifrare\n");
    scanf("%s",str);
    printf("Inescerisci chiave di cifratura\n");
    scanf(" %c",&c);
    cifrarioCesare(str,c,1);
    printf("La parola cifrata vale: %s\n",str);
    
    copiaStringa(str, oldStr);
    for (i='a';i<='z';i++){
        copiaStringa(oldStr, str);
        cifrarioCesare(str,i,0);
        printf("La parola decifrata con key = %c vale: %s",i,str);
    }
    return 0;
}

void cifrarioCesare(unsigned char stringa[], unsigned char key, int cifra){
    int i;
    unsigned char keyM, keym;
    
    if ((key>='a') && (key<='z')){
        keym = key;
        keyM = key-'a'+'A';
    }
    else{
        keyM = key;
        keym = key-'A'+'a';
    }
    for (i=0;stringa[i]!='\0';i++){
        if ((stringa[i]>='a') &&(stringa[i]<='z')){
            if (cifra==1)
                stringa[i] = stringa[i]-'a'+keym;
            else
                stringa[i] = stringa[i]-keym+'a';
            if (stringa[i]>'z')
                stringa[i] = stringa[i]-'z'+'a'-1;
            if (stringa[i]<'a')
                stringa[i] = stringa[i]-'a'+'z'+1;
        }
        else if ((stringa[i]>='A') &&(stringa[i]<='Z')){
            if (cifra==1)
                stringa[i] = stringa[i]-'A'+keyM;
            else
                stringa[i] = stringa[i]-keyM+'A';
            if (stringa[i]>'Z')
                stringa[i] = stringa[i]-'z'+'a'-1;
            if (stringa[i]<'A')
                stringa[i] = stringa[i]-'a'+'z'+1;
        }
    }
    printf("\n");
}

void copiaStringa(char str1[], char str2[]){
    int i;
    for (i=0; str1[i]!='\0'; i++)
        str2[i] = str1[i];
}
//abcdefghijklmnopqrstuvwxyz
//zabcdefghijklmnopqrstuvwxy
```
