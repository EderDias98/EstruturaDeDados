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

/**
 * @brief verifica se uma lista simples e vazia
 * @param lista ponteiro pra lista;
 * @return 1 se a lista e vazia e 0 se a lista nao e vazia
*/

int ehListaVaziaM(tListaM* lista){
    if(lista->primeiroNo == NULL)
        return 1;
    else return 0;
}

/**
 * @brief libera um no da lista
 * @param no ponteiro para um no da lista
*/

void liberaNoM(tNoM* no){
    free(no->item);
    free(no->desc);
    free(no);
}

/**
 * @brief cria um no da lista
 * @param item pertence ao no da lista
 * @return ponteiro para o no criado
*/

tNoM* criaNoM(char* item, char* desc){
    tNoM* no = (tNoM*) calloc(1, sizeof(tNoM));

    no->item = item;
    no->desc =desc;
    no->next = NULL;

    return no;
}


/**
 * @brief cria uma lista vazia com tamanho 0 
 * @return um ponteiro para lista que tem primeiro e ultimo no NULL
*/

tListaM* criaListaVaziaM(){
    tListaM* lista = (tListaM*) calloc(1, sizeof(tListaM));
    lista->primeiroNo = NULL;
    lista->ultimoNo = NULL;
    lista->tam =0;
    return lista;
}

/**
 * @brief inseri no no inicio da lista encadeada
 * @param lista ponteiro para a lista
 * @param item item do no a ser inserido
*/



/**
 * @brief inseri no no fim da lista encadeada
 * @param lista ponteiro para a lista
 * @param item item do no a ser inserido
*/

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

/**
 * @brief libera primeiro item da lista encadeada
 * @param lista ponteiro para a lista
*/

void liberaPrimeiroItemListaM(tListaM* lista){
    if(ehListaVaziaM(lista))
        return;

    //generico
    tNoM* primeiroNo = lista->primeiroNo;

    //lista so tem um no
    if(lista->ultimoNo == lista->primeiroNo)
        lista->ultimoNo = NULL;

    lista->primeiroNo = lista->primeiroNo->next;
    liberaNoM(primeiroNo);
    lista->tam--;

}

/**
 * @brief libera ultimo item da lista encadeada
 * @param lista ponteiro para a lista
*/

void liberaUltimoItemListaM(tListaM* lista){
    if(ehListaVaziaM(lista))
        return;



    tNoM* noAtual = lista->primeiroNo;
    tNoM* noAnterior = NULL;

    while(noAtual->next != NULL){
        noAnterior = noAtual;
        noAtual = noAtual->next;
    }

    //so tem um item na lista
    if(noAtual == lista->primeiroNo)
        lista->primeiroNo = NULL;
    else
        noAnterior->next =NULL;

    liberaNoM(lista->ultimoNo);
   
    lista->ultimoNo = noAnterior;
    lista->tam--;
}

int compProdutoM(char* item1, char* item2){
    if(strcmp(item1, item2) == 0)
        return 1;
    else return 0;
}

/**
 * @brief libera item da lista encadeada
 * @param lista ponteiro para a lista
 * @param item item a ser liberado na lista
*/
void liberaItemListaM(tListaM* lista, char* item){
    if(ehListaVaziaM(lista))
        return;

    if(compProdutoM(lista->primeiroNo->item, item)){
        liberaPrimeiroItemListaM(lista);
        return;
    }

    if(compProdutoM(lista->ultimoNo->item, item)){
        liberaUltimoItemListaM(lista);
        return;
    }


    tNoM* noAtual = lista->primeiroNo;
    tNoM* noAnterior = NULL;

    while(noAtual->next != NULL){
        noAnterior = noAtual;
        noAtual = noAtual->next;
        if(compProdutoM(noAtual->item, item))
            break;

    }
    //se o item nao esta na lista ele alcanca o ultimo no dela;
    if(noAtual->next == NULL)
        return;

    //generico
    noAnterior->next = noAtual->next;
    liberaNoM(noAtual);
    lista->tam--;

}


/**
 * @brief insere item na lista encadeada no index dado
 * @param lista ponteiro para a lista
 * @param item item a ser liberado na lista
 * @param  idx posicao em que sera inserido o item na lista
*/


/**
 * @brief libera item na lista encadeada no index dado
 * @param lista ponteiro para a lista
 * @param item item a ser liberado na lista
 * @param  idx posicao em que sera liberado o item na lista
*/
void liberaItemListaIdxM(tListaM* lista, int idx){

    if(idx<0 || idx >=lista->tam)
        return;
    
    tNoM* noAtual = lista->primeiroNo;
    tNoM* noAnterior = NULL;

    for(int i=1; i<=idx;i++){
        noAnterior = noAtual;
        noAtual = noAtual->next;
    }

    // o index e zero
    if(noAtual == lista->primeiroNo){
        liberaPrimeiroItemListaM(lista);
        return;    
    }

    if(noAtual == lista->ultimoNo){
        lista->ultimoNo = noAnterior;
    }

    noAnterior->next = noAtual->next;
    liberaNoM(noAtual);
    lista->tam--;
    
}

/**
 * @brief imprimi os itens da lista encadeada
 * @param lista ponteiro para lista 
*/
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

/**
 * @brief libera os nos da lista encadeada
 * @param lista ponteiro para lista 
*/

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

/**
 * @brief libera a lista encadeada
 * @param lista ponteiro para lista 
*/

void liberaListaM(tListaM* lista){
    if(!lista)
        return;
    liberaNosDaListaM(lista);
    free(lista);
}



tNoM* getNoListaL(tListaM* lista, char* nome){
    if(ehListaVaziaL(lista))
        return NULL;

    if(compProdutoM(lista->primeiroNo->item, nome)){
        return lista->primeiroNo;
    }

    if(compProdutoM(lista->ultimoNo->item, nome)){
        
        return lista->ultimoNo;
    }


    tNoM* noAtual = lista->primeiroNo;


    while(noAtual->next != NULL){

        noAtual = noAtual->next;
        if(compProdutoM(noAtual->item, nome)){
            return noAtual;
        }
    }

    printf("Nao tem esse nome na ListaM\n");
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

tNoM* copiaNoM(tNoM* no){
    tNoM* copia = criaNoM(no->item,no->desc);
    return copia;
}