#ifndef GATO_H
#define GATO_H

typedef struct gato Gato;
Gato* inicGato(char* nome, int estado);
char* copiaStr(char* str);

void imprimeGato(Gato* g);


void liberaGato(Gato* g);


char* getNomeGato(Gato * g);


int getEstadoGato(Gato* g);

void atribuiNivelAgressividadeGato(Gato* g, int estado);


#endif