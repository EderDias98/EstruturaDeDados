#include "Cachorro.h"
#include <stdio.h>
#include <stdlib.h>
#include "BanhoTosa.h"
#define MANSO 0
#define BRAVO 1


struct cachorro{
    int estado;
    char* nome;
};



Cachorro* inicCachorro(char* nome, int estado){
    Cachorro* c = (Cachorro*) malloc(sizeof(Cachorro));
    c->nome = strdup1(nome);
    c->estado = estado;
    return c;
}

void imprimeCachorro(Cachorro* c){

    char* estado1 = "MANSO";
    char* estado2 = "BRAVO";
    char* estado = estado1;
    if(c->estado == BRAVO)
        estado = estado2;
    
    printf("%s, %s; ", c->nome, estado);
}

void liberaCachorro(Cachorro* c){
    if(!c)
        return;
    free(c->nome);
    free(c);
}

int ehCaoBravo(Cachorro* c){
    if(c->estado == BRAVO)
        return 1;
    else return 0;
}
void atribuiNivelAgressividadeCachorro(Cachorro* c, int estado){
    c->estado = estado;
}

char* getNomeC(Cachorro* c){
    c->nome;
}