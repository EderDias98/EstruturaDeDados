#include "arvoreBuscaGenerica.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int main(){
    ARV* raiz = NULL;
    srand(time(NULL));
    for(int i=0; i<5;i++){
        ITEM* item = ItemInicia(i);
        raiz = ArvoreBuscaGenericaInsere(raiz, ItemCompara, item);
    }

    ArvoreBuscaGenericaImprime(raiz, ItemImprime,0);
    ITEM* item = ItemInicia(2);
    raiz =ArvoreBuscaGenericaRetira(raiz,ItemCompara,item);
    ArvoreBuscaGenericaImprime(raiz, ItemImprime,0);
    ArvoreBuscaGenericaLibera(raiz);
    return 0;
}