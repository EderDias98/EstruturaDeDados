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
 * @brief insere intem no index(0 - tam-1) como fazem o vetor a[2] = 3;
 * @param lista ponteiro pra lista
 * @param item ponteiro do item                          
 * @param idx posicao para inserir o item
 * @return 1 para sucesso e 0 para fracasso  
*/

int insereItemLista(tLista* lista,void* item,int idx){
    if(!(idx<lista->tam && idx>=0))
        return 0;
    

    tNo* novoNo = criaNovoNo();
    novoNo->item = item;
    

    tNo* noAtual = lista->primeiroNo;
    tNo* noAnterior = NULL;

    if(idx == 0){
        novoNo->next = lista->primeiroNo->next;
        
        //libera o primeiroNo
        liberaNo(lista,lista->primeiroNo);
        
        lista->primeiroNo = novoNo;
        return 1;
    }



    // no atual representa no no idx i;
    for(int i=1;i<=idx;i++){
        noAnterior = noAtual;
        noAtual = noAtual->next;
    }
    //


    if(idx == lista->tam-1){
        noAnterior->next = novoNo;
        //libera ultimo no

        liberaNo(lista,lista->ultimoNo);

        lista->ultimoNo = novoNo;
        
    }else{
        novoNo->next = noAtual->next;
        //libera no atual
        liberaNo(lista,noAtual);

        noAnterior->next = novoNo;
    }

   

    return 1;

}
// 0 1 2 3 4

/**
 * @brief retira item da lista
 * @param lista ponteiro pra lista
 * @param item ponteiro do item
 * @return 1 caso sucesso e 0 caso fracasso
*/

void retiraItemLista(tLista* lista, void* item){



    tNo* noAnterior = NULL;
    tNo* noAtual= lista->primeiroNo;

    // se o primeito item da lista é o procurado
    if(lista->comp(noAtual->item, item)){
        lista->primeiroNo = NULL;
        lista->ultimoNo = NULL;
            
        liberaNo(lista,noAtual);
        return;
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
            return;

        noAnterior->next = NULL;
        lista->ultimoNo = noAnterior;

        //libera noAtual
        liberaNo(lista,noAtual);
    }

    
    //geral
    noAnterior= noAtual->next;
    //liberar noAtual
    liberaNo(lista,noAtual);
}

// 0 1 2 3 4