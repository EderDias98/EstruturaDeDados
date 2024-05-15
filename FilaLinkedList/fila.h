#ifndef FILA_H
#define FILA_H

typedef struct no tNo;
typedef struct lista tLista;

tLista* iniciaFila();


void insereFiLa(tLista* lista, int item);

tNo* retiraFila(tLista* lista);
 
void imprimeFila(tLista*  lista);
    
 
void destroiFila(tLista* lista);
 

#endif