#include "Cachorro.h"
#include "string.h"
#include <stdlib.h>
#include <stdio.h>
#include "Gato.h"
#define BRAVO 1
#define MANSO 0
struct cachorro{
    char* nome;
    int estado;
};

Cachorro* inicCachorro(char* nome, int estado){
    Cachorro* c = (Cachorro*) malloc(sizeof(Cachorro));
    c->nome = copiaStr(nome);
    c->estado = estado;
    return c;
}

void imprimeCachorro(Cachorro* c){
    printf("%s ", c->nome);
}

void liberaCachorro(Cachorro* c){
    if(!c)
        return;
    
    free(c->nome);
    free(c);
}

char* getNomeCachorro(Cachorro * c){
    return c->nome;
}

int getEstadoCachorro(Cachorro* c){
    return c->estado;
}
void atribuiNivelAgressividadeCachorro(Cachorro* c, int estado){
    c->estado = estado;
}

