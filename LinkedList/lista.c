#include "lista.h"
#include <stdlib.h>
#include <produto.h>

struct No{
    void* item;
    struct No* next;
};



struct lista{
    tNo* primeiroNo;
    tNo* ultimoNo;
    int tam;
};

int ehListaVazia(tLista* lista){
    if(lista->primeiroNo == NULL)
        return 1;
    else return 0;
}

void liberaNo(tNo* no){
    liberaProduto(no->item);
    free(no);
}


tNo* criaNo(void* item){
    tNo* no = (tNo*) calloc(1, sizeof(tNo));

    no->item = item;
    no->next = NULL;

    return no;
}

tLista* criaListaVazia(){
    tLista* lista = (tLista*) calloc(1, sizeof(tLista));
    lista->primeiroNo = NULL;
    lista->ultimoNo = NULL;
    lista->tam =0;
    return lista;
}

void insereInicioLista(tLista* lista, void* item){
    tNo* novoNo = criaNo(item);

    //lista vazia
    if(ehListaVazia(lista))
        lista->ultimoNo = novoNo;

    // generico
    novoNo->next = lista->primeiroNo;
    lista->primeiroNo = novoNo;
    lista->tam++;

}

void insereFimLista(tLista* lista, void* item){
    tNo* novoNo = criaNo(item);

    //lista vazia
    if(ehListaVazia(lista))
        lista->primeiroNo = novoNo;
    else
        lista->ultimoNo->next = novoNo;


    //generico
 
    lista->ultimoNo = novoNo;
    lista->tam++;
}


void liberaPrimeiroItemLista(tLista* lista){
    if(ehListaVazia(lista))
        return;

    //generico
    tNo* primeiroNo = lista->primeiroNo;

    if(lista->ultimoNo == lista->primeiroNo)
        lista->ultimoNo = NULL;

    lista->primeiroNo = lista->primeiroNo->next;
    liberaNo(primeiroNo);
    lista->tam--;

}

void liberaUltimoItemLista(tLista* lista){
    if(ehListaVazia(lista))
        return;



    tNo* noAtual = lista->primeiroNo;
    tNo* noAnterior = NULL;

    while(noAtual->next != NULL){
        noAnterior = noAtual;
        noAtual = noAtual->next;
    }

    //so tem um item na lista
    if(noAtual == lista->primeiroNo)
        lista->primeiroNo= NULL;
    else
        noAnterior->next =NULL;

    liberaNo(lista->ultimoNo);
   
    lista->ultimoNo = noAnterior;
    lista->tam--;
}

void liberaItemLista(tLista* lista, void* item){
    if(ehListaVazia(lista))
        return;

    if(compProduto(lista->primeiroNo->item, item)){
        liberaPrimeiroItemLista(lista);
        return;
    }

    if(compProduto(lista->ultimoNo->item, item)){
        liberaUltimoItemLista(lista);
        return;
    }


    tNo* noAtual = lista->primeiroNo;
    tNo* noAnterior = NULL;

    while(noAtual->next != NULL){
        noAnterior = noAtual;
        noAtual = noAtual->next;
        if(compProduto(noAtual->item, item))
            break;

    }
    //o item nao esta na lista;
    if(noAtual->next == NULL)
        return;

    //generico
    noAnterior->next = noAtual->next;
    liberaNo(noAtual);
    lista->tam--;

}

void insereItemListaIdx(tLista* lista,void* item ,int idx){

    if(idx<0 || idx >=lista->tam)
        return;

    tNo* novoNo = criaNo(item);

    tNo* noAtual = lista->primeiroNo;
    tNo* noAnterior = NULL;

    for(int i=1; i<=idx;i++){
        noAnterior = noAtual;
        noAtual = noAtual->next;
    }


    // o index é 0
    if(noAtual == lista->primeiroNo){
        lista->primeiroNo = novoNo;
        novoNo->next = noAtual;
        lista->tam++;
        return;
    }
        
    //generico
    novoNo->next = noAtual;
    noAnterior->next = novoNo;
    lista->tam++;

}

void liberaItemListaIdx(tLista* lista, int idx){

    if(idx<0 || idx >=lista->tam)
        return;
    
    tNo* noAtual = lista->primeiroNo;
    tNo* noAnterior = NULL;

    for(int i=1; i<=idx;i++){
        noAnterior = noAtual;
        noAtual = noAtual->next;
    }

    // o index e zero
    if(noAtual == lista->primeiroNo){
        liberaPrimeiroItemLista(lista);
        return;    
    }

    if(noAtual == lista->ultimoNo){
        lista->ultimoNo = noAnterior;
    }

    noAnterior->next = noAtual->next;
    liberaNo(noAtual);
    lista->tam--;
    
}

void  imprimiLista(tLista* lista){

    if(ehListaVazia(lista))
        return;
    tNo* noAtual = lista->primeiroNo;
    for (int i = 0; i < lista->tam; i++){
        imprimiProduto(noAtual->item);
        noAtual = noAtual->next;
    }
    
}

void liberaNosDaLista(tLista* lista){
    if(ehListaVazia(lista))
        return;

    tNo* noAtual = lista->primeiroNo;
    tNo* noAnterior = NULL;

    while(noAtual->next != NULL){
        noAnterior = noAtual;
        noAtual = noAtual->next;
        liberaNo(noAnterior);
    }
    
    liberaNo(noAtual);
    lista->tam=0;
}

void liberaLista(tLista* lista){
    if(!lista)
        return;
    liberaNosDaLista(lista);
    free(lista);
}
// 0 1 2 3 4 5