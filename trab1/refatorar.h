#ifndef REFATORAR_H
#define REFATORAR_H

typedef struct autores tAutores;


tAutores* criaAutores();
void insereAutores(tAutores* autores, char*nome);
void liberaAutores(tAutores* autores);
void imprimiAutores(tAutores* autores);
int ehNomeUnico(tAutores* autores, char* nome);
#endif