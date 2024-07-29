#include "Lista.h"
#include "string.h"
#include <stdlib.h>
#include <stdio.h>
#include "Gato.h"
#include "Cachorro.h"

#define CACHORRO 1
#define GATO 0


struct no{
    int tipo;
    void* item;
    struct no* next;
};

struct lista{
    tNo* primeiro;
    tNo* ultimo;
};

tNo* iniciaNo(void* item, int tipo){
    tNo* no = (tNo*) malloc(sizeof(tNo));
    no->item = item;
    no->tipo = tipo;
    return no;
}

tLista* iniciaListaVazia(){
    tLista* li = (tLista*) malloc(sizeof(tLista));
    li->primeiro = NULL;
    li->ultimo = NULL;
    return li;
}

void insereNoLista(tLista* li, void* item, int tipo){
    tNo* no = iniciaNo(item,tipo);

    if(!li->primeiro){
        li->primeiro = no;
        li->ultimo = no;
    }else{
        li->ultimo->next = no;
        li->ultimo = no;
    }
}

int getNomeAnimal(void* item,int tipo){
    char* nome;
    if(tipo == CACHORRO){
        Cachorro* c = (Cachorro*) item;
        nome = getNomeCachorro(c);
    }else if(tipo == GATO){
        Gato* g = (Gato*) item;
        nome = getNomeGato(g);
    }

    return nome;
}

void* retiraItemLista(tLista* li, char * chave){
    tNo* p = li->primeiro;
    tNo* q = NULL;
    char* nome;


    while(p!=NULL && strcmp(getNomeAnimal(p->item,p->tipo),chave)){
        q = p;
        p = p->next;
    } 

    
}

void imprimeLista(tLista* li){
    tNo* p =li->primeiro;
    while(p!=NULL){

        if(p->tipo == GATO){
            imprimeGato((Gato*)p->item);
        }else if(p->tipo == CACHORRO){
            imprimeCachorro((Cachorro*) p->item);
        }

        p = p->next;
    }
}

void liberaLista(tLista* li){
    tNo* p =li->primeiro;
    tNo* q = NULL;
    while(p!=NULL){
        q= p->next;
        free(p);
        p = q;
    }
}