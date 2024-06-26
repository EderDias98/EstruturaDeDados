#include "arvoreDeBusca.h"

struct arv{
    tAluno* aluno;
    struct arv* dir;
    struct arv* esq;
};


//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
tArv* criaArvoreBusca(){
    return NULL;
}

void insereNaArvoreBusca(tArv** raiz, tAluno* aluno){
    if(*(raiz)!=NULL){

        if(ehMaiorAluno(aluno,(*raiz)->aluno)<=0){
            insereNaArvoreBusca(&((*raiz)->esq),aluno);
        }else{
            insereNaArvoreBusca(&((*raiz)->dir), aluno);
        }

    }else{
        (*raiz) = (tArv*) malloc(sizeof(tArv));
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        (*raiz)->aluno = aluno;
    }
    
}

tAluno* buscaNaArvoreBusca(tArv* raiz, tAluno* aluno){
    if(raiz==NULL)
        return NULL;

    if(!ehMaiorAluno(aluno,raiz->aluno)){
        return raiz->aluno;
    }

    if(ehMaiorAluno(aluno,raiz->aluno)<0){
        buscaNaArvoreBusca(raiz->esq,aluno);
    }else{
        buscaNaArvoreBusca(raiz->dir, aluno);
    }

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
        return !strcmp(getNomeAluno(a->aluno), nome) ||
        ArvPertence(a->esq, nome) ||
        ArvPertence(a->dir, nome);

    }

    
}

void ArvImprime (tArv* a, int nivel){
    if(!ArvVazia(a)){

        ArvImprime(a->esq,nivel+1);
        
        for(int i=0; i<nivel;i++) printf("  ");
        
        imprimeAluno(a->aluno);
        
        
        ArvImprime(a->dir,nivel+1);

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

int Ocorrencias(tArv* a, char * nome){
    if(!ArvVazia(a)){
        int cont = 0;
        if( !strcmp(getNomeAluno(a->aluno), nome)){
            cont = 1;
        }
        return cont + Ocorrencias(a->esq,nome) + Ocorrencias(a->dir,nome);
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