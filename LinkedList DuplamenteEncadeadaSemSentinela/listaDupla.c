#include "listaDupla.h"
#include <stdlib.h>
#include <stdio.h>
struct No{
    int item;
    struct No* next;
    struct No* prev;
};

int tamLista(tNo *no){

    tNo* noAtual = no;
    int tam=0;
    while(noAtual != NULL){
        tam++;
        noAtual = noAtual->next;
    }
    return tam;
}

tNo* criaNo(int item){
    tNo* no = (tNo*) malloc(sizeof(tNo));
    no->item = item;
    no->next = NULL;
    no->prev = NULL;

    return no;
}


/**
 * @brief insere o  no na posicao da lista encadeada, se quero inserir no comeco da lista
 * uso a posicao 1 e se for no final uso a posicao tam+1;
 * @param cabeca e um endereco que armazena o ponteiro da cabeca da lista
 * @param item o item da lista
 * @param posicao a posicao da lista indo de 1 a tam+1;
*/

void insereNoPosicao(tNo** cabeca, int item , int posicao){
    int k=1;
    tNo* p;
    tNo* novoNo = criaNo(item);
    int tam  = tamLista((*cabeca));

    if(posicao<1 || posicao> tam +1){
        printf("Erro de posicao\n");
        return;
    }

    if(posicao == 1){

        novoNo->next = (*cabeca);
        if(*cabeca)
            (*cabeca)->prev = novoNo;

        (*cabeca) = novoNo;
        return;
    }

    p = (*cabeca);

    while(( k< posicao-1 && p->next !=NULL )){
        k++;
        p = p->next;
    }
    
    novoNo->next = p->next;
    novoNo->prev = p;

    if(p->next)
        p->next->prev = novoNo;

    p->next = novoNo;
    return;
}


void insereItemInicio(tNo** cabeca, int item){

    tNo* novoNo = criaNo(item);


    novoNo->next = (*cabeca);
    if(*cabeca)
        (*cabeca)->prev = novoNo;
    (*cabeca) = novoNo;
}

void insereItemFinal(tNo** cabeca, int item){

    if((*cabeca)==NULL){
        insereItemInicio(cabeca,item);
        return;
    }


    tNo* p = (*cabeca);
    tNo* novoNo = criaNo(item);


    while(p->next != NULL){
        p = p->next;
    }
    novoNo->next = p->next;
    novoNo->prev = p;

    p->next = novoNo;
}

void LiberaIteminicio(tNo** cabeca){
    if((*cabeca)==NULL)
        return;
    
    tNo* p = (*cabeca);

    (*cabeca) = (*cabeca)->next;
    
    if(*cabeca)
            (*cabeca)->prev = NULL;
    free(p);
}
void LiberaItemFinal(tNo** cabeca){
    if((*cabeca)==NULL)
        return;

    tNo* p = (*cabeca);
    while(p->next != NULL){
        p = p->next;
    }
    
    /// 1 no
    if(p->prev)
        p->prev->next = NULL;
    else  
        (*cabeca) = NULL;
    
    free(p);
}

void LiberaNoPosicao(tNo** cabeca, int posicao){
    int k=1;
    tNo* q;
    tNo* p;
    int tam  = tamLista((*cabeca));

    if((*cabeca==NULL))
        return;

    if(posicao<1 || posicao> tam +1){
        printf("Erro de posicao\n");
        return;
    }

    p = (*cabeca);

    if( posicao==1){
        (*cabeca) = (*cabeca)->next;
        if(*cabeca)
            (*cabeca)->prev = NULL;
        free(p);
        return;    
    }
    


    while((p !=NULL && k< posicao)){
        k++;
        p = p->next;
    }
    q  = p->prev;
    q->next = p->next;
    //liberando no intermediario
    if(p->next)
        p->next->prev = q;
    free(p);
    return;
}

void liberaLista(tNo** cabeca){

    tNo*q;
    tNo*p = (*cabeca);
    while(p!=NULL){
        q = p->next;
        free(p);
        p = q;
    }
    // for(int i=1; i<=tam; i++){
    //     LiberaNoPosicao(cabeca,i);
    // }

    (*cabeca) =NULL;
}

void imprimiLista(tNo** cabeca){
    tNo* p;
    p = (*cabeca);
    while(p!=NULL){
        printf("%d ", p->item);
        p = p->next;
    }
    printf("\n");
}