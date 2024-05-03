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

/**
 * @brief verifica se uma lista simples e vazia
 * @param lista ponteiro pra lista;
 * @return 1 se a lista e vazia e 0 se a lista nao e vazia
*/

int ehListaVaziaP(tLista* lista){
    if(lista->primeiroNo == NULL)
        return 1;
    else return 0;
}

/**
 * @brief libera um no da lista
 * @param no ponteiro para um no da lista
*/

void liberaNoP(tNo* no){
    free(no->item);
    liberaListaM(no->lista);
    free(no);
}

/**
 * @brief cria um no da lista
 * @param item pertence ao no da lista
 * @return ponteiro para o no criado
*/

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
/**
 * @brief cria uma lista vazia com tamanho 0 
 * @return um ponteiro para lista que tem primeiro e ultimo no NULL
*/

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



/**
 * @brief inseri no no inicio da lista encadeada
 * @param lista ponteiro para a lista
 * @param item item do no a ser inserido
*/

void insereInicioListaP(tLista* lista, char* item){
    tNo* novoNo = criaNoP(item);

    //lista vazia
    if(ehListaVaziaP(lista))
        lista->ultimoNo = novoNo;

    // generico
    novoNo->next = lista->primeiroNo;
    lista->primeiroNo = novoNo;
    lista->tam++;
    // quando a lista e vazia o primeiro e ultimo no apontam para o mesmo no
}

/**
 * @brief inseri no no fim da lista encadeada
 * @param lista ponteiro para a lista
 * @param item item do no a ser inserido
*/

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

/**
 * @brief libera primeiro item da lista encadeada
 * @param lista ponteiro para a lista
*/

void liberaPrimeiroItemListaP(tLista* lista){
    if(ehListaVaziaP(lista))
        return;

    //generico
    tNo* primeiroNo = lista->primeiroNo;

    //lista so tem um no
    if(lista->ultimoNo == lista->primeiroNo)
        lista->ultimoNo = NULL;

    lista->primeiroNo = lista->primeiroNo->next;
    liberaNoP(primeiroNo);
    lista->tam--;

}

/**
 * @brief libera ultimo item da lista encadeada
 * @param lista ponteiro para a lista
*/

void liberaUltimoItemListaP(tLista* lista){
    if(ehListaVaziaP(lista))
        return;



    tNo* noAtual = lista->primeiroNo;
    tNo* noAnterior = NULL;

    while(noAtual->next != NULL){
        noAnterior = noAtual;
        noAtual = noAtual->next;
    }

    //so tem um item na lista
    if(noAtual == lista->primeiroNo)
        lista->primeiroNo = NULL;
    else
        noAnterior->next =NULL;

    liberaNoP(lista->ultimoNo);
   
    lista->ultimoNo = noAnterior;
    lista->tam--;
}

int compProdutoP(char* item1, char* item2){
    if(strcmp(item1, item2) == 0)
        return 1;
    else return 0;
}

/**
 * @brief libera item da lista encadeada
 * @param lista ponteiro para a lista
 * @param item item a ser liberado na lista
*/
void liberaItemListaP(tLista* lista, char* item){
    if(ehListaVaziaP(lista))
        return;

    if(compProdutoP(lista->primeiroNo->item, item)){
        liberaPrimeiroItemListaP(lista);
        return;
    }

    if(compProdutoP(lista->ultimoNo->item, item)){
        liberaUltimoItemListaP(lista);
        return;
    }


    tNo* noAtual = lista->primeiroNo;
    tNo* noAnterior = NULL;

    while(noAtual->next != NULL){
        noAnterior = noAtual;
        noAtual = noAtual->next;
        if(compProdutoP(noAtual->item, item))
            break;

    }
    //se o item nao esta na lista ele alcanca o ultimo no dela;
    if(noAtual->next == NULL)
        return;

    //generico
    noAnterior->next = noAtual->next;
    liberaNoP(noAtual);
    lista->tam--;

}


/**
 * @brief insere item na lista encadeada no index dado
 * @param lista ponteiro para a lista
 * @param item item a ser liberado na lista
 * @param  idx posicao em que sera inserido o item na lista
*/

void insereItemListaIdxP(tLista* lista,char* item ,int idx){

    if(idx<0 || idx >lista->tam)
        return;

    if(idx == lista->tam){
        insereFimListaP(lista,item);
        return;
    }

    if(idx == 0){
        insereInicioListaP(lista,item);
        return;
    }

    tNo* novoNo = criaNoP(item);

    tNo* noAtual = lista->primeiroNo;
    tNo* noAnterior = NULL;

    for(int i=1; i<=idx;i++){
        noAnterior = noAtual;
        noAtual = noAtual->next;
    }

    //generico
    novoNo->next = noAtual;
    noAnterior->next = novoNo;
    lista->tam++;

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
/**
 * @brief libera item na lista encadeada no index dado
 * @param lista ponteiro para a lista
 * @param item item a ser liberado na lista
 * @param  idx posicao em que sera liberado o item na lista
*/
void liberaItemListaIdxP(tLista* lista, int idx){

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
        liberaPrimeiroItemListaP(lista);
        return;    
    }

    if(noAtual == lista->ultimoNo){
        lista->ultimoNo = noAnterior;
    }

    noAnterior->next = noAtual->next;
    liberaNoP(noAtual);
    lista->tam--;
    
}

/**
 * @brief imprimi os itens da lista encadeada
 * @param lista ponteiro para lista 
*/
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

/**
 * @brief libera os nos da lista encadeada
 * @param lista ponteiro para lista 
*/

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

/**
 * @brief libera a lista encadeada
 * @param lista ponteiro para lista 
*/

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