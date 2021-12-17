#include <stdio.h>
#include <math.h>

float taylor(float x, float N);
int fattoriale(int n);

int main(){
    float N, x;
    
    printf("Inserisci x: ");
    scanf("%f", &x);
    printf("Inserisci N: ");
    scanf("%f", &N);
    
    printf("L'approssimazione in sin(%f) di Taylor con N = %f vale: %.5f\n\n", x, N, taylor(x,N));
    return 0;
}

float taylor(float x, float N){
    if (N==0)
        return x;
    else
        return (pow(-1,N) * pow(x,2*N+1)/(float)fattoriale(2*N+1))+taylor(x, N-1);
}

int fattoriale(int n){
    if ((n==0) || (n==1))
        return 1;
    else
        return n * fattoriale(n-1);
}
