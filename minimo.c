*/
//Scrivere una funziona ricorsiva per il calcolo del valore minimo di un array

#include <stdio.h>

int minimo(int val[], int len);

int main(){
    int val[] = {1,5,2,-9,4,1,3,-4,9,10};
    
    printf("Il minimo è %d\n",minimo(val,10));
    return 0;
}

int minimo(int val[], int len){
    if (len==1)
        return val[len-1];
    else{
        if (val[len-1]<minimo(val, len-1))
            return val[len-1];
        else
            return minimo(val, len-1);
    }
}
