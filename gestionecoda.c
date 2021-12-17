/*Gestisce una coda di persone. Ogni persona ha numero, nome, cognome. La coda riceve una nuova persona e le inserisce in coda, e le elimina dalla testa.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct persona{
    int id_persona;
    char nome[20];
    char cognome[20];
    struct persona *next;
} persona;

typedef persona* ptrPersona;

ptrPersona inserisciInCoda(ptrPersona lista);
ptrPersona inserisciInCodaRic(ptrPersona lista);
int rimuoviDallaCoda(ptrPersona *lista);
void stampaLista(ptrPersona lista);

int main()
{
    ptrPersona lista = NULL;
    int c;
    
    do{
        printf("MENU\n");
        printf("1) Inserisci in coda\n");
        printf("2) Prossimo cliente\n");
        printf("3) Stampa tutta la coda\n");
        printf("0) Esci\n>> ");
        scanf("%d",&c);
        
        switch (c) {
            case 1:
                lista = inserisciInCoda(lista);
                //lista = inserisciInCodaRic(lista);
                break;
            case 2:
                printf("Il prossimo cliente è: %d\n",rimuoviDallaCoda(lista));
                break;
            case 3:
                stampaLista(lista);
                break;
        }
        
    }while(c!=0);
    return 0;
}

ptrPersona inserisciInCoda(ptrPersona lista){
    ptrPersona nodo;
    ptrPersona testa = lista;
    
    nodo = (ptrPersona)malloc(sizeof(persona));
    printf("Inserisci id: ");
    scanf("%d",&((*nodo).id_persona));
    printf("Inserisci nome: ");
    scanf("%s", nodo->nome);
    printf("Inserisci cognome: ");
    scanf("%s", nodo->cognome);
    nodo->next = NULL;
    
    if (lista==NULL)
        return nodo;
    
    while(lista->next!=NULL)
        lista = lista->next;
    
    lista->next = nodo;
    return testa;
}

ptrPersona inserisciInCodaRic(ptrPersona lista){
    if (lista==NULL)
    {
        lista = (ptrPersona)malloc(sizeof(persona));
        printf("Inserisci id: ");
        scanf("%d",&lista->id_persona);
        printf("Inserisci nome: ");
        scanf("%s", lista->nome);
        printf("Inserisci cognome: ");
        scanf("%s", lista->cognome);
        lista->next = NULL;
        return lista;
    }
    else{
        lista->next = inserisciInCodaRic(lista->next);
        return lista;
    }
}
int rimuoviDallaCoda(ptrPersona *lista){ //rimuovi dalla testa della lista
    ptrPersona temp;
    int i;
    
    if ((*lista)==NULL)
        return -1;
    else{
        temp = (*lista);
        i = temp->id_persona;
        //printf nome cognome
        (*lista) = (*lista)->next;
        free(temp);
        return i;
    }
}

ptrPersona eliminaUltimoElemnto(ptrPersona lista, int *i){
    if (lista == NULL)
        return NULL;
    if (lista->next == NULL){
        *i = lista->id_persona;
        free(lista);
        return NULL;
    }
    else{
        lista->next = eliminaUltimoElemnto(lista->next, i);
        return lista;
    }
}

void stampaLista(ptrPersona lista){
    if (lista==NULL)
        return;
    printf("Id: %d Nome: %s Cognome: %s",lista->id_persona,lista->nome,(*lista).cognome);
    stampaLista(lista->next);
}
