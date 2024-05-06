#include "listaP.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listaM.h"

struct No{
    char* item;
    struct No* next;
    tListaM* lista;
};



struct lista{
    tNo* primeiroNo;
    tNo* ultimoNo;
    int tam;
};



int ehListaVaziaP(tLista* lista){
    if(lista->primeiroNo == NULL)
        return 1;
    else return 0;
}



void liberaNoP(tNo* no){
    free(no->item);
    liberaListaM(no->lista);
    free(no);
}



tNo* criaNoP(char* item){

    tNo* no = (tNo*) malloc(sizeof(tNo));

    no->item = item;
    no->next = NULL;
    no->lista = criaListaVaziaM();

    return no;
}

char* getNomeP(tNo* no){
    return no->item;
}

int getTamP(tLista* lista){
    return lista->tam;
}


tLista* criaListaVaziaP(){
    tLista* lista = (tLista*) calloc(1, sizeof(tLista));
    lista->primeiroNo = NULL;
    lista->ultimoNo = NULL;
    lista->tam =0;
    return lista;
}

void setListaMEmP(tNo* no, tListaM* lista){
    liberaListaM(no->lista);
    no->lista = lista;
}






void insereFimListaP(tLista* lista, char* item){
    tNo* novoNo = criaNoP(item);

    //lista vazia
    if(ehListaVaziaP(lista))
        lista->primeiroNo = novoNo;
    else
        lista->ultimoNo->next = novoNo;


    //generico
 
    lista->ultimoNo = novoNo;
    lista->tam++;
}





int compProdutoP(char* item1, char* item2){
    if(strcmp(item1, item2) == 0)
        return 1;
    else return 0;
}






tNo* getNoListaIdxP(tLista* lista,int idx){

    if(idx<0 || idx >lista->tam -1)
        return NULL;



    tNo* noAtual = lista->primeiroNo;


    if(idx == 0){
        return noAtual;
    }

    for(int i=1; i<=idx;i++){
        noAtual = noAtual->next;
    }

    return noAtual;

}


void  imprimiListaP(tLista* lista){

    if(ehListaVaziaP(lista))
        return;
    tNo* noAtual = lista->primeiroNo;
    for (int i = 0; i < lista->tam; i++){
        printf("\n%s\n", noAtual->item);
        imprimiListaM(noAtual->lista);
        noAtual = noAtual->next;
    }

    printf("\n");
}



void liberaNosDaListaP(tLista* lista){
    if(ehListaVaziaP(lista))
        return;

    tNo* noAtual = lista->primeiroNo;
    tNo* noAnterior = NULL;

    while(noAtual->next != NULL){
        noAnterior = noAtual;
        noAtual = noAtual->next;
        liberaNoP(noAnterior);
    }
    
    liberaNoP(noAtual);
    lista->tam=0;
}



void liberaListaP(tLista* lista){
    if(!lista)
        return;
    liberaNosDaListaP(lista);
    free(lista);
}

tListaM* getListaMDeP(tNo* no){
    return no->lista;
}
// 0 1 2 3 4 5