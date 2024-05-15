#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

struct no{
    int item;
    struct no* next;
};

struct lista{
    struct no* primeiro;
    struct no* ultimo;
    int tam;
};

tLista* iniciaPilha(){
    tLista* pilha = (tLista*) malloc(sizeof(tLista));
    pilha->primeiro = NULL;
    pilha->ultimo = NULL;
    pilha->tam = 0;
    return pilha;
}

void push(tLista* p, int n){
    tNo* novoNo = (tNo*) malloc(sizeof(tNo));
    novoNo->item =n;
    novoNo->next = NULL;
    //a pilha esta vazia
    if(!p->primeiro){
        p->primeiro = novoNo;
        p->ultimo = novoNo;
    }else{
        //a pilha tem mais de um elemento
        p->ultimo->next = novoNo;
        p->ultimo = novoNo;
    }
    p->tam++;
}

int pop(tLista* p){
    if(!p->primeiro)
        return -1;

    tNo* no = p->ultimo;
    tNo* q = p->primeiro;
    tNo* a = NULL;
    while (q->next!=NULL)
    {
        a = q;
        q = q->next;
    }
    
    //tem um elemento
    if(p->primeiro == q)
        p->primeiro =NULL;
    //tem mais de um elemento
    else a->next =NULL;

    p->ultimo = a;
    p->tam--;
    return no->item;
}

void imprimePilha(tLista* p){
    tNo* q = p->primeiro;
    while(q!=NULL){
        printf("%d ", q->item);
        q = q->next; 
    }
    printf("\n");
}

void destroiPilha(tLista* p){
    if(!p)
        return;
    free(p);
}