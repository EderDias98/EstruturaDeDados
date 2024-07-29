#ifndef ARVORE_BUSCA_H
#define ARVORE_BUSCA_H
#include "aluno.h"

typedef struct arv tArv;
//Cria uma árvore vazia


tArv* ArvoreDeBuscaCria();

tAluno* ArvoreDeBuscaGetAluno(tArv* raiz);
 

tArv* ArvoreDeBuscaInsere(tArv* raiz, tAluno* aluno);


tArv* ArvoreDeBuscaBusca(tArv* raiz, tAluno* aluno);

void ArvoreDeBuscaImprime (tArv* a, int nivel);
tArv* ArvoreDeBuscaRemove(tArv* raiz, tAluno* aluno);

//busca

void ArvoreDeBuscaLibera(tArv* raiz);
int ArvoreDeBuscaFolhas(tArv* raiz);

tArv* ArvoreDeBuscaBalancea(tArv* raiz);

#endif