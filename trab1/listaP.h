#ifndef LISTA_H
#define LISTA_H

#include "listaM.h"

typedef struct No tNo;
typedef struct lista tLista;

tLista* criaListaVaziaP();

void insereInicioListaP(tLista* lista, char* item);// correta
 
void insereFimListaP(tLista* lista, char* item); // correta
 
void liberaPrimeiroItemListaP(tLista* lista); // correta

void liberaUltimoItemListaP(tLista* lista); //correta
 
void liberaItemListaP(tLista* lista, char* item); // correta

void insereItemListaIdxP(tLista* lista,char* item ,int idx); //correto 

void liberaItemListaIdxP(tLista* lista, int idx); // correto

void  imprimiListaP(tLista* lista); // correto

void liberaNosDaListaP(tLista* lista); //correto

void liberaListaP(tLista* lista); //correto


char* getNomeP(tNo* no);
tNo* getNoListaIdxP(tLista* lista,int idx);
int getTamP(tLista* lista);
void setListaMEmP(tNo* no, tListaM* lista);


char* getListaMDeP(tNo* no);
#endif