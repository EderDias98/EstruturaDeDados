#ifndef GATO_H
#define GATO_H


typedef struct gato Gato;


Gato* inicGato(char* nome, int estado);

void imprimeGato(Gato* g);

void liberaGato(Gato* g);

int ehGatoBravo(Gato* g);
char getNomeG(Gato* g);
#endif