#include "arvoreBuscaGenerica.h"

#include <stdio.h>
#include <stdlib.h>

struct arv{
    void* item;
    struct arv *esq;
    struct arv *dir;
};



ARV* ArvoreBuscaGenericaCria(void* item){
    ARV* raiz = (ARV*) malloc(sizeof(ARV));
    raiz->item = item;
    raiz->esq = NULL;
    raiz->dir = NULL;
    return raiz;
}

void ArvoreBuscaGenericaImprime(ARV* raiz,void (*callbackImprime)(void*), int nivel){
    if(raiz!=NULL){
        ArvoreBuscaGenericaImprime(raiz->esq,callbackImprime, nivel+1);
        for(int i=0; i<nivel;i++) printf(" ");
        callbackImprime(raiz->item);
        ArvoreBuscaGenericaImprime(raiz->dir,callbackImprime, nivel+1);
    }   
}

void ArvoreBuscaGenericaLibera(ARV* raiz){
    if(raiz==NULL) return;
    
    ArvoreBuscaGenericaLibera(raiz->esq);
    ArvoreBuscaGenericaLibera(raiz->dir);
    ItemLibera(raiz->item);
    free(raiz);
    
}

ARV* ArvoreBuscaGenericaInsere(ARV* raiz, int (*callbackCompara)(void*,void*), void* item){
    if(raiz == NULL){
        return ArvoreBuscaGenericaCria(item);
    }
    
    if(callbackCompara(item, raiz->item)<=0){
        raiz->esq = ArvoreBuscaGenericaInsere(raiz->esq,callbackCompara, item);
        
    }else {
        raiz->dir =ArvoreBuscaGenericaInsere(raiz->dir,callbackCompara, item);
    }
    return raiz;
}

ITEM* ArvoreBuscaGenericaBusca(ARV* raiz, int (*callbackCompara)(void*,void*), void* item){
    
    if(raiz ==NULL)
        return NULL;
        
    if(callbackCompara(item, raiz->item) == -1){
        return ArvoreBuscaGenericaBusca(raiz->esq,callbackCompara, item);
    }else if(callbackCompara(item, raiz->item) == 1) {
        return ArvoreBuscaGenericaBusca(raiz->dir,callbackCompara, item);
    }else if(callbackCompara(item, raiz->item) == 0){
        return raiz->item;
    }
}

ARV* ArvoreBuscaGenericaRetira(ARV* raiz,int (*callbackCompara)(void*, void*), void* item){
    if(callbackCompara(item,raiz->item) == -1){
        raiz->esq =  ArvoreBuscaGenericaRetira(raiz->esq,callbackCompara,item);
    }else if(callbackCompara(item,raiz->item) == 1){
        raiz->dir =  ArvoreBuscaGenericaRetira(raiz->dir, callbackCompara, item);
    }else{
        // to no no que sera removido
        
        // 1 caso
        //o no é um folha
        if(raiz->esq == NULL && raiz->dir ==NULL){
            ItemLibera(raiz->item);
            free(raiz);
            raiz = NULL;
        }
        // no com um filho na direita
        else if(raiz->esq == NULL){
            ARV* temp = raiz;

            raiz = raiz->dir;
            
            ItemLibera(temp->item);
            free(temp);
        }
        // no com um filho na esquerda
        else if(raiz->dir == NULL){
            ARV* temp = raiz;
            raiz = raiz->esq;
            ItemLibera(temp->item);
            free(temp);
        }
        // no com dois filhos
        else{
            ARV* no = raiz->esq;
            while(no->dir !=NULL){
                no = no->dir;
            }
            raiz->item = no->item;
            no->item = item;
            raiz->esq =  ArvoreBuscaGenericaRetira(raiz->esq,callbackCompara ,item);
        }
    }
    return raiz;
}