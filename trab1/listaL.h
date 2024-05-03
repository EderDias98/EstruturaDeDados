#ifndef LISTA_L
#define LISTA_L
#include "listaP.h"



typedef struct NoL tNoL;
typedef struct listaL tListaL;
typedef struct amigos tAmigos;

tListaL* criaListaVaziaL();

void insereInicioListaL(tListaL* lista, char* item);// correta
 
void insereFimListaL(tListaL* lista, char* item); // correta
 
void liberaPrimeiroItemListaL(tListaL* lista); // correta

void liberaUltimoItemListaL(tListaL* lista); //correta
 
void liberaItemListaL(tListaL* lista, char* item); // correta

void insereItemListaIdxL(tListaL* lista,char* item ,int idx); //correto 

void liberaItemListaIdxL(tListaL* lista, int idx); // correto

void  imprimiListaL(tListaL* lista); // correto

void liberaNosDaListaL(tListaL* lista); //correto

void liberaListaL(tListaL* lista); //correto


void InsereAmigoListaL(tNoL* atual, char* nome);
tNoL* getNoListaL(tListaL* lista, char* nome);


void setListaPEmL(tNoL* no, tLista* lista);

int getTamL(tListaL* lista);
tNoL* getNoListaIdxL(tListaL* lista,int idx);
tLista* getListaPDeL(tNoL* no);
char* getNomeL(tNoL* no);
void criaSimilaridades(tListaL* listaL);
#endif