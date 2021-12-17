/*
 Lista di caratteri che gestisce una pila di caratteri. La pila è una lista nella quale i nuovi elementi vengono sempre inseriti in testa (push). Quando si legge un elemento (pop) estra dalla testa. (FILO)
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    char carattere;
    struct nodo* next;
} nodo;

typedef nodo* ptrNodo;

ptrNodo inserisciInPila(ptrNodo lista);
ptrNodo rimuoviDaPila(ptrNodo lista, char *letto);
char rimuoviDaPila2(ptrNodo *lista);
void stampaLista(ptrNodo lista);
void stampaListaContrario(ptrNodo lista);

int main(){
    ptrNodo lista = NULL;
    char cc;
    int c;
    
    do{
        printf("MENU\n");
        printf("1) Inserisci in pila\n");
        printf("2) Rimuovi dalla pila\n");
        printf("3) Stampa la pila\n");
        printf("4) Stampa pila al contrario\n");
        printf("0) Esci\n>> ");
        scanf("%d",&c);
        
        switch (c) {
            case 1:
                lista = inserisciInPila(lista);
                break;
            case 2:
                if (lista == NULL)
                    printf("La lista è vuota\n");
                else{
                    printf("Carattere letto: %c",rimuoviDaPila2(&lista));
                    //lista = rimuoviDaPila(lista, &cc);
                    //printf("Carattere letto: %c",cc);
                }
                break;
            case 3:
                stampaLista(lista);
                break;
                
            case 4:
                stampaListaContrario(lista);
                break;
                
            default:
                break;
        }
    }while(c!=0);
    return 0;
}

ptrNodo inserisciInPila(ptrNodo lista){
    ptrNodo temp;
    temp = (ptrNodo)malloc(sizeof(nodo));
    printf("Inserisci il carattere: ");
    scanf(" %c",&(temp->carattere));
    temp->next = lista;
    return temp;
}

ptrNodo rimuoviDaPila(ptrNodo lista, char *letto){
    ptrNodo temp;
    if(lista==NULL)
    {
        *letto = ' ';
        return NULL;
    }
    else{
        *letto = lista->carattere;
        temp = lista;
        lista = lista->next;
        free(temp);
        return lista;
    }
}
char rimuoviDaPila2(ptrNodo *lista){
    char c;
    ptrNodo temp;
    if (*lista == NULL)
        return ' ';
    else{
        c = (*lista)->carattere;
        temp = *lista;
        *lista = (*lista)->next;
        free(temp);
        return c;
    }
    
}

void stampaLista(ptrNodo lista){
    if (lista == NULL){
        printf("\n");
        return;
    }
    printf("%c ",lista->carattere);
    stampaLista(lista->next);
}

void stampaListaContrario(ptrNodo lista){
    if (lista == NULL){
        printf("\n");
        return;
    }
    stampaListaContrario(lista->next);
    printf("%c ",lista->carattere);
}
