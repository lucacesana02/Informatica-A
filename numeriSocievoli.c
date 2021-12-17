 #include <stdio.h>

int sommaDivisori(int n);
int socievoli(int a, int b);

int main(int argc, const char * argv[]) {
    int read;
    int n=0;
    int old;
    
    do{
        
        scanf("%d",&read);
        if (read<0)
            continue;
        n++;
        if (n<2){
            printf("Non ho inserito numeri sufficienti\n");
        }
        else{
            if (socievoli(old,read)==1)
                printf("La catena fin ora inserita è di numeri socievoli\n");
            else {
                printf("La catena non è di numeri socievoli\n");
                read = -1;
            }
        }
        old = read;
    }while(read>=0);
}

int sommaDivisori(int n){
    int i;
    int somma = 0;
    for (i=1; i<n; i++){
        if (n%i==0)
            somma+=i; //somma = somma+i;
    }
    return somma;
}

int socievoli(int a, int b){
    if (sommaDivisori(a)==b)
        return 1;
    return 0;
}
