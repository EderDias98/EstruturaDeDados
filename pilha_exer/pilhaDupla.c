#include "pilhaDupla.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define TAM_MAX 6
typedef struct bt_pilha{
    int base;
    int topo;
}tBt_pilha;



struct pilha{
    tGato* item[TAM_MAX];
    tBt_pilha pilha1;
    tBt_pilha pilha2;
};

tBt_pilha iniciaBtPilha(int b,int t){
    tBt_pilha bt;
    bt.base = b;
    bt.topo = t;
    return  bt;
}

tPilha* iniciaPilha(){
    tPilha* p = (tPilha*) malloc(sizeof(tPilha));
    p->pilha1= iniciaBtPilha(0,0);
    p->pilha2 = iniciaBtPilha(TAM_MAX-1, TAM_MAX-1);
    return p;
}

void pushPilha1(tPilha* p,tGato* g){
    if(!p || p->pilha1.topo  > p->pilha2.topo){
        printf("Pilha cheia\n");
        return ;
    }
    p->item[p->pilha1.topo] = g;
    p->pilha1.topo++;
}

tGato* popPilha1(tPilha* p){
    if(!p || p->pilha1.topo == p->pilha1.base){
        printf("Pilha vazia\n");
    }
    tGato* g = p->item[p->pilha1.topo-1];
    p->pilha1.topo--;
    return g;
}

void imprimePilha1(tPilha* p){
    for(int i = p->pilha1.topo-1; i>=p->pilha1.base;i--){
        imprimeGato(p->item[i]);
    }
    printf("\n");
}

void pushPilha2(tPilha*p, tGato* g){
    if(!p || p->pilha1.topo > p->pilha2.topo){
        printf("Pilha cheia\n");
        return;
    }
    p->item[p->pilha2.topo] = g;
    p->pilha2.topo--;
}

tGato* popPilha2(tPilha* p){
    if(!p || p->pilha2.topo == p->pilha2.base){
        printf("Pilha vazia\n");
    }
    tGato* g = p->item[p->pilha2.topo+1];
    p->pilha2.topo++;
    return g;
}

void imprimePilha2(tPilha* p){
    for( int i = p->pilha2.topo+1; i<=p->pilha2.base ; i++){
        imprimeGato(p->item[i]);
    }
    printf("\n");
}

void liberaPilha(tPilha* p){
    if(!p)
        return;
    free(p);
}