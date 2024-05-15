#include "listaSimples.h"
#include <stdlib.h>
#include <stdio.h>
struct No{
    int item;
    struct No* next;
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
    tNo* q;
    tNo* p;
    tNo* novoNo = criaNo(item);
    int tam  = tamLista((*cabeca));

    if(posicao<1 || posicao> tam +1){
        printf("Erro de posicao\n");
        return;
    }

    if(posicao == 1){
        novoNo->next = (*cabeca);
        (*cabeca) = novoNo;
        return;
    }

    p = (*cabeca);

    while((p !=NULL && k< posicao)){
        k++;
        q =  p;
        p = p->next;
    }

    q->next = novoNo;
    novoNo = p->next;
}

void LiberaNoPosicao(tNo** cabeca, int posicao){
    int k=1;
    tNo* q;
    tNo* p;
    int tam  = tamLista((*cabeca));

    if(posicao<1 || posicao> tam +1){
        printf("Erro de posicao\n");
        return;
    }

    if( posicao==1){
        q = (*cabeca);
        (*cabeca) = (*cabeca)->next;
        free(q);
        return;    
    }
    
    p = (*cabeca);

    while((p !=NULL && k< posicao)){
        k++;
        q =  p;
        p = p->next;
    }
    
    if(p == NULL){
        printf("Posicao nao existe");
    }else{
        q->next = p->next;
        free(p);
    }
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