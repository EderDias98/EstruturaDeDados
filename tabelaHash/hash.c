
#include "hash.h"
#include <stdlib.h>
#include <string.h>


PALAVRA** HashInicia(){
    PALAVRA** hash =(PALAVRA**) calloc(TAM_TAB, sizeof(PALAVRA*));
    return hash;
}

int HashFunc(char *p){
    int total=0;
    for(int i=0; p[i]!='\0';i++){
        total += p[i];
    }
    return total %TAM_TAB;
}

void HashInsere(PALAVRA** hash, char *p){
    int h = HashFunc(p);
    PALAVRA* pal = hash[h] ;
    if(pal == NULL){
        // criar lista de palavra
        PALAVRA* pal = PalavraInicializa(p);
        hash[h] = pal;
    }else{
        // procurar indice da palavra na lista
        //se nao estiver criar e colocar no inicio
        while(pal!=NULL){
            if(strcmp(p, pal->p)==0){
                pal->frq++;
                break;
            }
            pal = pal->prox;
        }

        if(pal == NULL){
            //palavra nao esta na lista
            PALAVRA* pal = PalavraInicializa(p);
            pal->prox = hash[h];
            hash[h] = pal;
        }
    }
}

PALAVRA* HashBusca(PALAVRA** hash, char *p){
    int h = HashFunc(p);
    PALAVRA* pal = hash[h] ;

    while(pal!=NULL){
        if(strcmp(p, pal->p) == 0)
            return pal;
        pal = pal->prox;
    }
    return NULL;
}

int HashQuantidade(PALAVRA** hash){
    int total = 0;
    for(int i=0; i<TAM_TAB;i++){
        PALAVRA* pal = hash[i];
        while(pal!= NULL){
            total++;
            pal = pal->prox;
        }
    }
    return total;
}

