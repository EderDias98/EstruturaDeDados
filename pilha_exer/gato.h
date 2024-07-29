#ifndef GATO_H
#define GATO_H

typedef struct gato tGato;
tGato* inicGato(char* nome, int estado);
char* copiaStr(char* str);

void imprimeGato(tGato* g);


void liberaGato(tGato* g);


char* getNomeGato(tGato * g);


int getEstadoGato(tGato* g);

void atribuiNivelAgressividadeGato(tGato* g, int estado);


#endif