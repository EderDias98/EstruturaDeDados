#include "Lista.h"
#include <stdlib.h>
#include "Gato.h"
#include "Cachorro.h"
#include <stdio.h>
#include <string.h>
struct no{
    int tipo;
    void* item;
    struct no* next;
};

struct lista{
  tNo* primeiro;
  tNo* ultimo;  
};

tLista* iniciaLista(){
    tLista* lista = (tLista*) malloc(sizeof(tLista));
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    return lista;
}

tNo* iniciaNo(int tipo, void* item ){
    tNo* no = (tNo*) malloc(sizeof(tNo));
    no->tipo = tipo;
    no->item = item;
    return no;
}

void insereLista(tLista*li, void* item, int tipo){
    tNo* no = iniciaNo(tipo, item);

    if(!li->primeiro){
        li->primeiro = no;
        li->ultimo =no; 
    }else {
        li->ultimo->next = no;
        li->ultimo = no;
    }
}

int ehIgual(tNo* no , char* nome){
    if(no->tipo == GATO){
        if(strcmp(nome,getNomeG((Gato*) no->item)) == 0)
            return 1;
    }else{
        if(strcmp(nome,getNomeC((Cachorro*) no->item)) == 0)
            return 1;
    }

    return 0;
}

void* retiraLista(tLista* li, char* chave){
    tNo* p= li->primeiro;
    tNo* q = NULL;
    void* item = NULL;

    while(p!=NULL && !ehIgual(p,chave)){
        q=p;
        p = p->next;
    }

    if(p == NULL)
        return NULL;
    
    item  = p->item;
    if(li->primeiro == li->ultimo){
        li->primeiro = li->ultimo = NULL;
    }else if(p == li->primeiro){
        li->primeiro = p->next;
    }else if(p == li->ultimo){
        li->ultimo = q;
        li->ultimo->next = NULL;
    }else{
        q->next = p->next;
    }

    return item;
}   

void liberaLista(tLista* li){
    tNo* p = li->primeiro;
    tNo* temp = NULL;

    while (p!=NULL){
        temp = p->next;
        free(p);
        p = temp;
    }
    free(li);
}

void imprimeLista(tLista* li){
    tNo* p = li->primeiro;

    while(p!=NULL){
        
        if(p->tipo == GATO){
            imprimeGato( (Gato*) p->item);
        }else{  
            imprimeCachorro((Cachorro*) p->item);
        }
        p = p->next;
    }
    printf("\n");
}

float receitaLista(tLista* li){
    tNo* p = li->primeiro;
    float rec =0;
    while(p!=NULL){
        
        if(p->tipo == GATO){
            rec +=30;
            if(ehGatoBravo((Gato*) p->item))
                rec +=5;
        }else{
            rec+=40;
            if(ehCaoBravo((Cachorro*) p->item))
                rec +=5;
        }

        p = p->next;
    }
    return rec;
}