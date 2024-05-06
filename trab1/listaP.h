#ifndef LISTA_H
#define LISTA_H

#include "listaM.h"

typedef struct No tNo;
typedef struct lista tLista;

/**
 * @brief cria uma listaP vazia com tamanho 0 
 * @return um ponteiro para listaP que tem primeiro e ultimo noP como NULL
*/
tLista* criaListaVaziaP();

/**
 * @brief verifica se a listaP e vazia
 * @param lista ponteiro pra listaP;
 * @return 1 se a listaP e vazia e 0 se a listaP nao e vazia
*/
int ehListaVaziaP(tLista* lista);

/**
 * @brief inseri noP no fim da listaP
 * @param lista ponteiro para a listaP
 * @param item ponteiro do item do noP a ser inserido
*/
void insereFimListaP(tLista* lista, char* item); 

/**
 * @brief imprimi os itens da listaP
 * @param lista ponteiro para listaP
*/
void  imprimiListaP(tLista* lista); 

/**
 * @brief libera os nosM da listaP
 * @param lista ponteiro para listaP
*/
void liberaNosDaListaP(tLista* lista); 

/**
 * @brief libera a listaP
 * @param lista ponteiro para listaP
*/
void liberaListaP(tLista* lista); 

/**
 * @brief  pega o ponteiro do nome da playlist
 * @param no o ponteiro do noP 
 * @return o ponteiro do nome da playlist
*/
char* getNomeP(tNo* no);

/**
 * @brief  pega o noP da ListaP representado pelo idx
 * @param lista ponteiro da listaP
 * @param idx o index do noP requerido
 * @return o ponteiro do noP requerido 
*/
tNo* getNoListaIdxP(tLista* lista,int idx);

/**
 * @brief  pega tam da listaP
 * @param lista ponteiro da listaP
 * @return o tamanho da listaP
*/
int getTamP(tLista* lista);

/**
 * @brief libera a listaM antiga do noP e coloca a listaM nova
 * @param no noP que tem a listaM
 * @param lista a listaM a ser colocada no lugar
*/
void setListaMEmP(tNo* no, tListaM* lista);

/**
 * @brief  pega o ponteiro da listaM presente no noP
 * @param no o ponteiro do noP presente na listaP
 * @return o ponteiro da listaM presente no noP
*/
tListaM* getListaMDeP(tNo* no);
#endif