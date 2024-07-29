#include "pilhaDupla.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define TAM_MAX 15
#define N 4
typedef struct bt_pilha{
    int base;
    int topo;
}tBt_pilha;



struct pilha{
    tGato* item[TAM_MAX];
    tBt_pilha pilhas[N];
};

tBt_pilha iniciaBtPilhaN(int b,int t){
    tBt_pilha bt;
    bt.base = b;
    bt.topo = t;
    return  bt;
}


tPilha* iniciaPilhaN(){
    tPilha* p = (tPilha*) malloc(sizeof(tPilha));
    // iniciar as bases e topos da n pilhas;
    int tam = TAM_MAX/N;
    int resto = TAM_MAX%N;
    
   
    int b = 0;
    for(int i=0; i<N;i++){
        
        p->pilhas[i] = iniciaBtPilhaN(b,b);
        
        b += tam;

        if(resto)
            b++;
        resto--;
    } 
    return p;   
}

void pushN(tPilha* p, int n,tGato* g){
    tBt_pilha bt0 = p->pilhas[n];
    tBt_pilha bt1 = p->pilhas[n+1];
    if(!p || bt0.topo == bt1.base){
        printf("Pilha cheia\n");
        return;
    }
    p->item[bt0.topo] = g;
    p->pilhas[n].topo++;

}

tGato* popN(tPilha* p, int n){
    tBt_pilha bt0 = p->pilhas[n];
    
    if(!p || bt0.topo == bt0.base){
        printf("Pilha vazia\n");
        return NULL;
    }
    tGato* g = p->item[bt0.topo -1];
    p->pilhas[n].topo --;
    return g;
}

void imprimeN(tPilha* p, int n){
    tBt_pilha bt0 = p->pilhas[n];
    for(int i= bt0.topo-1; i>=bt0.base; i--){
        imprimeGato(p->item[i]);
    }
    printf("\n");
}

void liberaPilhaN(tPilha* p){
    if(!p)
        return;
    free(p);
}   

