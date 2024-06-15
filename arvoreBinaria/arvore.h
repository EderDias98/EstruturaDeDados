#ifndef ARVORE_H
#define ARVORE_H
#include "aluno.h"

typedef struct arv tArv;
//Cria uma árvore vazia
tArv* arvCriaVazia (void);
//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
tArv* ArvCria (tAluno* alu, tArv* e, tArv* d);
//libera o espaço de memória ocupado pela árvore a
tArv* ArvLibera (tArv* a);
//retorna true se a árvore estiver vazia e false
//caso contrário
int ArvVazia (tArv* a);
//indica a ocorrência (1) ou não (0) do caracter c
int ArvPertence (tArv* a, char* nome);
//imprime as informações dos nós da árvore
void ArvImprime (tArv* a);
//retorna a quantidade de folhas da arvore
int Folhas(tArv* a);
//retorna quantas vezes o aluno aparece na arvore
int Ocorrencias(tArv* a, char * nome);
// retorna altura
int Altura(tArv* a);

#endif