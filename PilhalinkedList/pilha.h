#ifndef PILHA_H
#define PILHA_H

typedef struct no tNo;
typedef struct lista tLista;

tLista* iniciaPilha();

void push(tLista* p, int n);

int pop(tLista* p);

void imprimePilha(tLista* p);
 
void destroiPilha(tLista* p);

#endif