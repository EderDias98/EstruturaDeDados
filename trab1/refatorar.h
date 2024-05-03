#ifndef REFATORAR_H
#define REFATORAR_H
#include "listaL.h"
#include "listaM.h"
#include "listaP.h"
typedef struct autores tAutores;


tAutores* criaAutores();
tAutores* preencheAutores(tLista* listaP);
void insereAutores(tAutores* autores, char*nome);
void liberaAutores(tAutores* autores);
void imprimiAutores(tAutores* autores);
int ehNomeUnico(tAutores* autores, char* nome);
char *copiaPalavra(const char *palavra);
tLista* criaPlaylistFatorada(tAutores* autores, tLista* ListaP);
void refatoraListaL(tListaL* listaL);
void criaPastasEArquivos(tListaL* listaL);
char* getNomeAutor(tAutores* autores, int idx);
#endif