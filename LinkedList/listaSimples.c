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
    int tam;
};

struct no{
    void* item;
    tNo* next;
};

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

tLista* criaLista(void (*freeFun)(void *), int (*comp)(const void *, const void *)){
    tLista* lista = (tLista*) calloc(1, sizeof(tLista));

    // lista esta vazia
    lista->primeiroNo = NULL;
    lista->ultimoNo = NULL;
    lista->freeFun = freeFun;
    lista->comp = comp;

    return lista;
}

/**
 * @brief Cria novo no da Lista
 * @return ponteiro para o novo no
*/

tNo* CriaNovoNo(){
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
    tNo* novoNo = CriaNovoNo();
    
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
    tNo* novoNo = CriaNovoNo();
    
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
    lista->freeFun(noParaFree->item);
    free(noParaFree);
    lista->tam--;
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
    free(noParaFree);
    lista->tam--;
}