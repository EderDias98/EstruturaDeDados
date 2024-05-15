#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM 10
struct pilha{
    int topo;//indice do espaço vazio logo depois do ultimo elemento cheio da pilha
    int vet[TAM];
};

tPilha* iniciaPilha(){
    tPilha* pilha = (tPilha*) malloc(sizeof(tPilha));
    pilha->topo = 0; // nessa implementaçao oa pilha com topo 0 esta vazia
    return pilha;
}

void push(tPilha* p, int n){
    if(!p || p->topo==TAM)
        return;
    
    p->vet[p->topo] = n;
    p->topo++;
}

int pop(tPilha* p){
    if(!p || p->topo ==0) 
        return -1;

    int n= p->vet[p->topo-1];
    p->topo--;
    return n;
}

void imprimePilha(tPilha* p){
    for(int i=(p->topo -1);i>=0;i--)
        printf("%d ", p->vet[i]);
    
}

void destroiPilha(tPilha* p){
    if(!p)
        return;
    free(p);
}