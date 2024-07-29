#ifndef PILHA_D
#define PILHA_D
#include "gato.h"

typedef struct pilha tPilha;

tPilha* iniciaPilha();

void pushPilha1(tPilha* p,tGato* g);
  
tGato* popPilha1(tPilha* p);
 

void imprimePilha1(tPilha* p);


void pushPilha2(tPilha*p, tGato* g);


tGato* popPilha2(tPilha* p);


void imprimePilha2(tPilha* p);


void liberaPilha(tPilha* p);

#endif