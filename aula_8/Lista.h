#ifndef LISTA_H
#define LISTA_H
#define GATO 0
#define CACHORRO 1


typedef struct lista tLista;
typedef struct no tNo;
tLista* iniciaLista();

void insereLista(tLista*li, void* item, int tipo);

void* retiraLista(tLista* li, char* chave);

void liberaLista(tLista* li);

void imprimeLista(tLista* li);
float receitaLista(tLista* li);
#endif