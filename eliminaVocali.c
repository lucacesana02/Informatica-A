//Scrivere una funzione che, letta una stringa, elimini le vacali (prima solo a video, e poi dall'array);

#include <stdio.h>
#include <string.h>

void nonVocali(char stringa[]);
void nonVocali2(char stringa[]);

int main(){
    char stringa[30] = {"ciao come va?"};
    
    //nonVocali(stringa);
    nonVocali2(stringa);
    printf("%s\n",stringa);
    return 0;
}

void nonVocali(char stringa[]){
    if (*stringa == '\0'){
        printf("\n");
        return;
    }
    
    switch (*stringa) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            break;
            
        default:
            printf("%c",*stringa);
            break;
    }
    nonVocali(stringa+1);
}

void nonVocali2(char stringa[]){
    if (*stringa == '\0')
        return;
    switch (*stringa) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            memcpy(stringa,stringa+1,strlen(stringa+1));
            nonVocali2(stringa);
            break;
            
        default:
            nonVocali2(stringa+1);
            break;
    }
}
