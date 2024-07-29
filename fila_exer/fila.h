#ifndef FILA_H
#define FILA_H

#define TAM_MAX 10
#include "amostra.h"

typedef struct fila tFila;

tFila* iniciaFila(int tamMax);

void insereFila(tFila* f, Amostra* a);


Amostra* retiraFila(tFila* f);

void imprimeFila(tFila* f);

void liberaFila(tFila* f);

int getQuantidadeFila(tFila* f);
#endif