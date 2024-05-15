#ifndef PILHA_H
#define PILHA_H

typedef struct pilha tPilha;

tPilha* iniciaPilha();

void push(tPilha* p, int n);
    
int pop(tPilha* p);

void imprimePilha(tPilha* p);

void destroiPilha(tPilha* p);


#endif