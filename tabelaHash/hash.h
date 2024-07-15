#ifndef HASH_H
#define HASH_H
#include "palavra.h"
#define TAM_TAB 10000
PALAVRA** HashInicia();


int HashFunc(char *p);


void HashInsere(PALAVRA** hash, char *p);

PALAVRA* HashBusca(PALAVRA** hash, char *p);

int HashQuantidade(PALAVRA** hash);


#endif
