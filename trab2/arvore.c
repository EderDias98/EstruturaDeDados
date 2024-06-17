#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arv{
    int peso;
    int ch; // é iqual -1 se o no nao for folha isto é nao tiver caractere
    struct arv* dir;
    struct arv* esq;
};

tArv* arvCriaVazia (void){
    return NULL;
}
//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
tArv* ArvCria (int peso, int ch, tArv* e, tArv* d){
    tArv* p = (tArv*) malloc(sizeof(tArv));
    p->peso = peso;
    p->ch = ch;
    p->dir = d;
    p->esq = e;
    return p;
}

int ArvVazia (tArv* a){
    return a==NULL;
}

tArv* ArvLibera (tArv* a){
    if(!ArvVazia(a)){
        ArvLibera(a->esq);
        ArvLibera(a->dir);
        free(a);
    }

    return NULL;
}

int ArvPertence (tArv* a, int ch){
    if(ArvVazia(a)){
        return 0;
    }
    else{
        return a->ch == ch ||
        ArvPertence(a->esq, ch) ||
        ArvPertence(a->dir, ch);

    }

    
}

void ArvImprime (tArv* a){
    if(!ArvVazia(a)){
        printf("%c ",a->ch);
        ArvImprime(a->esq);
        ArvImprime(a->dir);
    }
}

//retorna a quantidade de folhas da arvore
int Folhas(tArv* a){
    if(ArvVazia(a)){
        return 0;
    }
    
    if(a->esq == NULL && a->dir == NULL){
        return 1;
    }
    

    return Folhas(a->esq)+ Folhas(a->dir);
}

int Ocorrencias(tArv* a, char * ch){
    if(!ArvVazia(a)){
        int cont = 0;
        if( a->ch == ch){
            cont = 1;
        }
        return cont + Ocorrencias(a,a->esq) + Ocorrencias(a,a->dir);
    }

    return 0;

}

int max(int a, int b){
    return (a>b)? a : b;
}

int Altura(tArv* a){
    if(ArvVazia(a)){
        return -1;
    }
    return 1+  max(Altura(a->esq), Altura(a->dir));
}

int getPeso(tArv* a){
    return a->peso;
}
int getCaractere(tArv* a){
    return a->ch;
}
// Função para combinar duas menores árvores em uma nova
tArv* combinaArvores(tArv* t1, tArv* t2) {
    tArv* nova_arvore = ArvCria(t1->peso+ t2->peso,-1,t1,t2);
    

    return nova_arvore;
}