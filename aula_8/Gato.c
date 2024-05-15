#include "Gato.h"
#include <stdio.h>
#include <stdlib.h>
#include "BanhoTosa.h"
#define MANSO 0
#define BRAVO 1


struct gato{
    int estado;
    char* nome;
};



Gato* inicGato(char* nome, int estado){
    Gato* g = (Gato*) malloc(sizeof(Gato));
    g->nome = strdup1(nome);
    g->estado = estado;
    return g;
}

void imprimeGato(Gato* g){

    char* estado1 = "MANSO";
    char* estado2 = "BRAVO";
    char* estado = estado1;
    if(g->estado == BRAVO)
        estado = estado2;
    
    printf("%s, %s; ", g->nome, estado);
}

void liberaGato(Gato* g){
    if(!g)
        return;
    free(g->nome);
    free(g);
}
int ehGatoBravo(Gato* g){
    if(g->estado == BRAVO)
        return 1;
    else return 0;
}
void atribuiNivelAgressividadeGato(Gato* g, int estado){
    g->estado = estado;
}

char getNomeG(Gato* g){
    return g->nome;
}