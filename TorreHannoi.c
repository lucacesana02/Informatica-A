#include <stdio.h>

void hanoi(int n, char from, char to, char with);

int main(){
    int n_anelli;
    printf("Quanti anelli ci sono sul pilone A? ");
    scanf("%d",&n_anelli);
    hanoi(n_anelli, 'A', 'C', 'B');
    return 0;
}

void hanoi(int n, char from, char to, char with){
    if (n != 0){
        hanoi(n-1, from, with, to);
        printf("Sposto un cerchi da %c a %c\n",from, to);
        hanoi(n-1, with, to, from);
    }
}