#include "listaSimples.h"
#include <stdlib.h>
#include <stdio.h>

struct listaSimples{
    /* data */
    // ponteiros apontando para o primeiro e ultimos elemento de minha lista
    tNo* primeiroNo;
    tNo* ultimoNo;

    void (*freeFun)(void *);
    int (*comp)(const void *, const void *);
    void (*printFun)(void *);
    int tam;
};

struct no{
    void* item;
    tNo* next;
};


void liberaNo(tLista* lista, tNo* no){
    lista->freeFun(no->item);
    free(no);
}


/**
 * @brief Responde se a lista é vazia
 * @param lista endereco da lista
 * @return 1 pra lista vazia e 0 pra lista nao vazia;
*/
int EhListaVazia(tLista* lista){
    if(lista->primeiroNo==NULL && lista->ultimoNo ==NULL)
        return 1;
    else return 0;
}


/**
 * @brief Cria uma lista vazia
 * @param freeFun funçao pra liberar o iten da lista
 * @param comp funcao pra comparar os itens da lista
 * @return ponteiro para uma lista vazia
*/

tLista* criaLista(void (*freeFun)(void *), int (*comp)(const void *, const void *), void (*printFun)(void *)){
    tLista* lista = (tLista*) calloc(1, sizeof(tLista));

    // lista esta vazia
    lista->primeiroNo = NULL;
    lista->ultimoNo = NULL;
    lista->freeFun = freeFun;
    lista->comp = comp;
    lista->freeFun = printFun;

    return lista;
}

/**
 * @brief Cria novo no da Lista
 * @return ponteiro para o novo no
*/

tNo* criaNovoNo(){
    tNo* novoNo = (tNo*) calloc(1, sizeof(tNo));
    if(!novoNo){
        printf("ERRO DE ALOCACAO DE MEMORIA DO NOVO NO\n");
        exit(-1);
    }

    novoNo->item = NULL;
    novoNo->next = NULL;
    return novoNo;
}



/**
 * @brief Adicionar um item no inicio da lista
 * @param lista endereco da lista
 * @param item endereco do item
*/

void AdInicioLista(tLista *lista, void *item){
    tNo* novoNo = criaNovoNo();
    
    novoNo->item = item;
    novoNo->next = lista->primeiroNo;
    
    
    //no caso
    if( EhListaVazia(lista))
        lista->ultimoNo = novoNo;


    lista->primeiroNo = novoNo;
    lista->tam++;
}

/**
 * @brief Adicionar um item no Fim da lista
 * @param lista endereco da lista
 * @param item endereco do item
*/

void AdFimLista(tLista *lista, void *item){
    tNo* novoNo = criaNovoNo();
    
    novoNo->item = item;
    novoNo->next = NULL;

    if(EhListaVazia(lista))
        lista->primeiroNo= novoNo;
    else
        lista->ultimoNo->next = novoNo;
    
    
    lista->ultimoNo = novoNo;
}

/**
 * @brief deletar o primeiro item da lista
 * @param lista endereco da lista
*/

void deletaInicioLista(tLista* lista){
    //lista vazia
    if(EhListaVazia(lista))
        return;
    
    
    
    tNo* noParaFree = lista->primeiroNo;

    //lista com um elemento
    if(lista->primeiroNo == lista->ultimoNo)
        lista->ultimoNo = NULL;
    

    //caso geral
    lista->primeiroNo = lista->primeiroNo->next;
    lista->tam--;
    liberaNo(lista,noParaFree);
}

/**
 * @brief deletar o ultimo item da lista
 * @param lista endereco da lista
*/

void deletaFimLista(tLista* lista){
    //lista vazia
    if(EhListaVazia(lista))
        return;
    
    tNo* noAtual = lista->primeiroNo;
    tNo* noAnterior = NULL;

    while(noAtual->next){
        noAnterior = noAtual;
        noAtual = noAtual->next;
    }
    
    tNo* noParaFree = noAtual; 

    // lista com um elemento
    if( noAnterior == NULL)
        lista->primeiroNo = NULL;
    else 
        noAnterior->next = NULL;
    
    //caso geral
    lista->ultimoNo = noAnterior;
    lista->freeFun(noParaFree->item);
    lista->tam--;
    liberaNo(lista,noParaFree);
}


/**
 * @brief retira item da lista
 * @param lista ponteiro pra lista
 * @param item ponteiro do item
 * @return 1 caso sucesso e 0 caso fracasso
*/

int retiraItemLista(tLista* lista, void* item){

    tNo* noAnterior = NULL;
    tNo* noAtual= lista->primeiroNo;

    // se o primeito item da lista é o procurado
    if(lista->comp(noAtual->item, item)){
        deletaInicioLista(lista);
        return 1;
    }
    



    while(noAtual->next!=NULL){

        noAnterior = noAtual;
        noAtual = noAtual->next;
        
        if(lista->comp(noAtual->item, item))
            break;

        
    }


    //se o ultimo item da lista é o achado ou o nao acha o item
    if(noAtual->next == NULL ){
        
        if(!lista->comp(noAtual->item, item))
            return 0;

        deletaFimLista(lista);
        return 1;
    }

    
    //geral
    noAnterior = noAtual->next;
    //liberar noAtual
    liberaNo(lista,noAtual);
    lista->tam--;
    return 1;
}


/**
 * @brief retira item da lista
 * @param lista ponteiro pra lista
 * @param idx index do elemento retirado
 * @return 1 caso sucesso e 0 caso fracasso
*/

int retiraItemListaNoIdx(tLista* lista, int idx){

    if(idx<0 || idx>= lista->tam)
        return 0;

    tNo* noAnterior = NULL;
    tNo* noAtual = lista->primeiroNo;

    for(int i=0; i<idx;i++){
        noAnterior = noAtual;
        noAtual = noAtual->next;
    }

    if(noAtual == lista->primeiroNo){
        deletaInicioLista(lista);
    }else if(noAtual == lista->ultimoNo){
        deletaFimLista(lista);
    }else{
        noAnterior = noAtual->next;
        liberaNo(lista,noAtual);
        lista->tam--;
    }


    return 1;
}

/**
 * @brief inserir um item num idex especifico, imagine
 * @param lista ponteiro pra lista
 * @param item ponteiro do item
 * @param idx index a ser iserido o item
 * @return 1 caso sucesso e 0 caso fracasso
*/

int isereItemNoIndxLista(tLista* lista,void* item ,int idx){
    // Conferir se operação é possivel
    
    if(idx<0 || idx>= lista->tam){     
        return 0;
    }

    tNo* novoNo = criaNovoNo();
    novoNo->item = item;

    tNo* noAnterior = NULL;
    tNo* noAtual = lista->primeiroNo;

    for(int i=0; i<idx;i++){
        noAnterior = noAtual;
        noAtual = noAtual->next;
    }

    if(noAtual == lista->primeiroNo){
        AdInicioLista(lista, item);
    }else{
        noAnterior->next = novoNo;
        novoNo->next = noAtual;
    }
    
    lista->tam++;
    return 1;

// 0 1 2 3 4 5 

        
}