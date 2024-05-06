#include "listaM.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listaP.h"
struct NoM{

    // nome do autor ou banda
    char* item;
    // nome da musica e descricao
    char* desc;
    struct NoM* next;
};



struct listaM{
    tNoM* primeiroNo;
    tNoM* ultimoNo;
    int tam;
};



int ehListaVaziaM(tListaM* lista){
    if(lista->primeiroNo == NULL)
        return 1;
    else return 0;
}


void liberaNoM(tNoM* no){
    free(no->item);
    free(no->desc);
    free(no);
}



tNoM* criaNoM(char* item, char* desc){
    tNoM* no = (tNoM*) calloc(1, sizeof(tNoM));

    no->item = item;
    no->desc =desc;
    no->next = NULL;

    return no;
}



tListaM* criaListaVaziaM(){
    tListaM* lista = (tListaM*) calloc(1, sizeof(tListaM));
    lista->primeiroNo = NULL;
    lista->ultimoNo = NULL;
    lista->tam =0;
    return lista;
}





void insereFimListaM(tListaM* lista, char* item, char* desc){
    tNoM* novoNo = criaNoM(item, desc);

    //lista vazia
    if(ehListaVaziaM(lista))
        lista->primeiroNo = novoNo;
    else
        lista->ultimoNo->next = novoNo;


    //generico
 
    lista->ultimoNo = novoNo;
    lista->tam++;
}





int compProdutoM(char* item1, char* item2){
    if(strcmp(item1, item2) == 0)
        return 1;
    else return 0;
}







void  imprimiListaM(tListaM* lista){

    if(ehListaVaziaM(lista))
        return;
    tNoM* noAtual = lista->primeiroNo;
    for (int i = 0; i < lista->tam; i++){
        printf("%s %s\n", noAtual->item, noAtual->desc);
        noAtual = noAtual->next;
    }
    printf("\n");
}



void liberaNosDaListaM(tListaM* lista){
    if(ehListaVaziaM(lista))
        return;

    tNoM* noAtual = lista->primeiroNo;
    tNoM* noAnterior = NULL;

    while(noAtual->next != NULL){
        noAnterior = noAtual;
        noAtual = noAtual->next;
        liberaNoM(noAnterior);
    }
    
    liberaNoM(noAtual);
    lista->tam=0;
}



void liberaListaM(tListaM* lista){
    if(!lista)
        return;
    liberaNosDaListaM(lista);
    free(lista);
}



tNoM* getNoListaM(tListaM* lista, char* nome){
    if(ehListaVaziaM(lista))
        return NULL;

    if(compProdutoM(lista->primeiroNo->desc, nome)){
        return lista->primeiroNo;
    }

    if(compProdutoM(lista->ultimoNo->desc, nome)){
        
        return lista->ultimoNo;
    }


    tNoM* noAtual = lista->primeiroNo;


    while(noAtual->next != NULL){

        noAtual = noAtual->next;
        if(compProdutoM(noAtual->desc, nome)){
            return noAtual;
        }
    }

    
    return NULL;
}



tNoM* getNoListaIdxM(tListaM* lista,int idx){

    if(idx<0 || idx >lista->tam -1)
        return NULL;



    tNoM* noAtual = lista->primeiroNo;


    if(idx == 0){
        return noAtual;
    }

    for(int i=1; i<=idx;i++){
        noAtual = noAtual->next;
    }

    return noAtual;

}

char* getAutorM(tNoM* no){
    return no->item;
}
char* getDescM(tNoM* no){
    return no->desc;
}

int getTamM(tListaM* lista){
    return lista->tam;
}

