#ifndef LISTA_H
#define LISTA_h

#include "aluno.h"

typedef struct lista tLista;

tLista* iniciaLista();

void insereListaInicio(tLista* li, tAluno* alu);

void insereListaFinal(tLista* li, tAluno* alu);

tAluno* retiraLista(tLista* li, char* chave);

tAluno* retiraListaPosicao(tLista* li, int posi);

void insereListaPosicao(tLista* li,tAluno* alu ,int pos);

void imprimeLista(tLista* li);

void destroiLista(tLista* li);

int getTamLista(tLista* li);
#endif