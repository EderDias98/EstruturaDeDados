#include "arvoresAvl.h"
#include <stdio.h>
#include <stdlib.h>


struct avlArv{
    int dado;
    tAvlArv* esq;
    tAvlArv* dir;
    int height;
};

int AvlArvGetHeight(tAvlArv* raiz){
    if(raiz==NULL)
        return 0;
    return raiz->height;
}

int max(int a, int b){
    return (a>b)? a :b;
}

int AvlArvCalculaHeight(tAvlArv* raiz){
    if(raiz == NULL)
        return 0; //  pode ser 0 ou -1 , com zero começa do 1 e com -1 começamos por 0 
    return 1 + max(AvlArvCalculaHeight(raiz->esq), AvlArvCalculaHeight(raiz->dir));
}

tAvlArv* RotacaoUnicaEsq(tAvlArv* X){
    tAvlArv* W = X->esq;
    X->esq = W->dir;
    W->dir = X;
    //recalcular a altura de X e W
    X->height = AvlArvCalculaHeight(X);
    W->height = AvlArvCalculaHeight(W);
    return W; 
}
tAvlArv* RotacaoUnicaDir(tAvlArv* X){
    tAvlArv* W = X->dir;
    X->dir = W->esq;
    W->esq = X;
    //recalcular a altura de X e W
    X->height = AvlArvCalculaHeight(X);
    W->height = AvlArvCalculaHeight(W);
    return W; 
}

tAvlArv* RotacaoDuplaEsq(tAvlArv* X){
    X->esq = RotacaoUnicaDir(X->esq);
    return RotacaoUnicaEsq(X);
}

tAvlArv* RotacaoDuplaDir(tAvlArv* X){
    X->dir = RotacaoUnicaEsq(X->dir);
    return RotacaoUnicaDir(X);
}


tAvlArv* AvlArvInsere(tAvlArv* raiz, int dado){
    if(raiz == NULL){
        tAvlArv* no = malloc(sizeof(tAvlArv));
        no->dado = dado;
        no->dir = NULL;
        no->esq = NULL;
        no->height = 1;
        return no;
    }

    if(dado > raiz->dado){
        raiz->dir = AvlArvInsere(raiz->dir,dado);
        
        if ( (AvlArvGetHeight(raiz->esq) -  AvlArvGetHeight(raiz->dir)) == -2 ){
            if(dado > raiz->dir->dado){
                //caso 4
                raiz = RotacaoUnicaDir(raiz);
            }else{
                //caso3
                raiz = RotacaoDuplaDir(raiz);
            }
        }
    }else if(dado <= raiz->dado){
        raiz->esq = AvlArvInsere(raiz->esq,dado);
        
        if((AvlArvGetHeight(raiz->esq) -  AvlArvGetHeight(raiz->dir)) == 2 ){
            if(dado <= raiz->esq->dado ){

                //caso1
                raiz = RotacaoUnicaEsq(raiz);

            }else{
                //caso2
                raiz = RotacaoDuplaEsq(raiz);
            }
        }
    }

    raiz->height = AvlArvCalculaHeight(raiz);
    return raiz;
}


void AvlArvImprime(tAvlArv* raiz, int nivel){
    if(raiz ==NULL)
        return;
    AvlArvImprime(raiz->esq, nivel+1);
    for(int i=0; i<nivel ;i++) printf(" ");
    printf("%d\n",raiz->dado);
    AvlArvImprime(raiz->dir, nivel+1);
}