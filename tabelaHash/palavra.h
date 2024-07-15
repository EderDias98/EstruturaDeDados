#ifndef PALAVRA_H
#define PALAVRA_H


#define TAM_PAL 100
#include <stdlib.h>
#include <stdio.h>

struct palavra{
    char p[TAM_PAL];
    int frq; // frequencia da palavra
    struct palavra * prox;
};

typedef struct palavra PALAVRA;

int PalavraLe(FILE* f, char*p);
PALAVRA* PalavraInicializa(char*str);
PALAVRA** PalavraCriaVetorOrdenado(PALAVRA** hash, int tam);
void PalavraImprimeVet(PALAVRA** vet, int tam);
#endif