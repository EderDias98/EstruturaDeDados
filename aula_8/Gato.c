#include "Gato.h"
#include "string.h"
#include <stdlib.h>
#include <stdio.h>
#define BRAVO 1
#define MANSO 0

char* copiaStr(char* str){
    int tam = strlen(str)+1;
    char* copia = malloc(tam);
    memcpy(copia,str,tam);

    return copia;
}


struct gato{
    char* nome;
    int estado;
};

Gato* inicGato(char* nome, int estado){
    Gato* g = (Gato*) malloc(sizeof(Gato));
    g->nome = copiaStr(nome);
    g->estado = estado;
    return g;
}

void imprimeGato(Gato* g){
    printf("%s ", g->nome);
}

void liberaGato(Gato* g){
    if(!g)
        return;
    
    free(g->nome);
    free(g);
}

char* getNomeGato(Gato * g){
    return g->nome;
}

int getEstadoGato(Gato* g){
    return g->estado;
}
void atribuiNivelAgressividadeGato(Gato* g, int estado){
    g->estado = estado;
}


