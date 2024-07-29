#ifndef PILHA_N
#define PILHA_N
#include "gato.h"
typedef struct pilha tPilha;

tPilha* iniciaPilhaN();
  

void pushN(tPilha* p, int n,tGato* g);


tGato* popN(tPilha* p, int n);

void imprimeN(tPilha* p, int n);
  

void liberaPilhaN(tPilha* p);
  



#endif