#ifndef ARVORE_BUSCA_GENERICA
#define ARVORE_BUSCA_GENERICA
#include "item.h"
typedef struct arv ARV;


void ArvoreBuscaGenericaImprime(ARV* raiz,void (*callbackImprime)(void*), int nivel);
void ArvoreBuscaGenericaLibera(ARV* raiz);
ARV* ArvoreBuscaGenericaCria(void* item);
ARV* ArvoreBuscaGenericaInsere(ARV* raiz, int (*callbackCompara)(void*,void*), void* item);
ITEM* ArvoreBuscaGenericaBusca(ARV* raiz,int (*callbackCompara)(void*, void*), void* item);
ARV* ArvoreBuscaGenericaRetira(ARV* raiz,int (*callbackCompara)(void*, void*), void* item);


#endif