#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

struct no{
    int item;
    struct no *next;
};


struct lista{
    struct no* primeiro;
    struct no* ultimo;
    int tam;
};

tLista* iniciaFila(){
    tLista* fila = (tLista*) malloc(sizeof(tLista));
    fila->primeiro=NULL;
    fila->ultimo = NULL;
    fila->tam=0;
    return fila;
}

void insereFiLa(tLista* lista, int item){
    tNo* no =(tNo*) malloc(sizeof(tNo));
    no->item = item;
    no->next = NULL;

    
    if(!lista->primeiro){
        lista->primeiro = no;
        lista->ultimo = no;
    } else{
        lista->ultimo->next = no;
        lista->ultimo = no;
    }
    lista->tam++;
}

tNo* retiraFila(tLista* lista){
    if(!lista->primeiro)
        return NULL;
    
    tNo* no = lista->primeiro;

    if(lista->primeiro == lista->ultimo)
        lista->ultimo = NULL;
    lista->primeiro = lista->primeiro->next;

    return no;
    
}

void imprimeFila(tLista*  lista){
    
    tNo* p =  lista->primeiro;
    while ( p!=NULL){
        printf("%d ", p->item);
        p = p->next;
    }
}

void destroiFila(tLista* lista){
    tNo* p =  lista->primeiro;
    tNo* temp = NULL;
    while ( p!=NULL){
        temp = p->next;
        free(p);
        p = temp;
    }
}