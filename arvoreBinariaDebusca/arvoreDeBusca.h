#ifndef ARVORE_BUSCA_H
#define ARVORE_BUSCA_H
#include "aluno.h"

typedef struct arv tArv;
//Cria uma árvore vazia


tArv* criaArvoreBusca();
 

void insereNaArvoreBusca(tArv** raiz, tAluno* aluno);


tAluno* buscaNaArvoreBusca(tArv* raiz, tAluno* aluno);

void ArvImprime (tArv* a, int nivel);
#endif