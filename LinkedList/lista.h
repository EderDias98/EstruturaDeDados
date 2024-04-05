#ifndef LISTA_H
#define LISTA_H
typedef struct No tNo;
typedef struct lista tLista;

tLista* criaListaVazia();

void insereInicioLista(tLista* lista, void* item);// correta
 
void insereFimLista(tLista* lista, void* item); // correta
 
void liberaPrimeiroItemLista(tLista* lista); // correta

void liberaUltimoItemLista(tLista* lista); //correta
 
void liberaItemLista(tLista* lista, void* item); // correta

void insereItemListaIdx(tLista* lista,void* item ,int idx); //correto 

void liberaItemListaIdx(tLista* lista, int idx); // correto

void  imprimiLista(tLista* lista); // correto

void liberaNosDaLista(tLista* lista); //correto

void liberaLista(tLista* lista); //correto
 
#endif