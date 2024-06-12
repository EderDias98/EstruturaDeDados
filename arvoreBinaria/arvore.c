#include "arvore.h"

struct arv{
    tAluno* aluno;
    struct arv* dir;
    struct arv* esq;
};

tArv* arvCriaVazia (void){
    return NULL;
}
//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
tArv* ArvCria (tAluno* alu, tArv* e, tArv* d){
    tArv* p = (tArv*) malloc(sizeof(tArv));
    p->aluno = alu;
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

int ArvPertence (tArv* a, char* nome){
    if(ArvVazia(a)){
        return 0;
    }
    else{
        return getNomeAluno(a->aluno) == nome ||
        ArvPertence(a->esq, nome) ||
        ArvPertence(a->dir, nome);

    }

    
}

void ArvImprime (tArv* a){
    if(!ArvVazia(a)){
        imprimeAluno(a->aluno);
        ArvImprime(a->esq);
        ArvImprime(a->dir);
    }
}