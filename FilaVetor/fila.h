#ifndef FILA_H
#define FILA_H

typedef struct fila tFila;
tFila* iniciaFila();
void insereFila(tFila* f, int n);
int retiraFila(tFila* f);
void imprimeFila(tFila* f);
void destroiFila(tFila* f);

#endif