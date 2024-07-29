#include "gato.h"
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

tGato* inicGato(char* nome, int estado){
    tGato* g = (tGato*) malloc(sizeof(tGato));
    g->nome = copiaStr(nome);
    g->estado = estado;
    return g;
}

void imprimeGato(tGato* g){
    printf("%s ", g->nome);
}

void liberaGato(tGato* g){
    if(!g)
        return;
    
    free(g->nome);
    free(g);
}

char* getNomeGato(tGato * g){
    return g->nome;
}

int getEstadoGato(tGato* g){
    return g->estado;
}
void atribuiNivelAgressividadeGato(tGato* g, int estado){
    g->estado = estado;
}


