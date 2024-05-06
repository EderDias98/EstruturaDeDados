#ifndef REFATORAR_H
#define REFATORAR_H
#include "listaL.h"
#include "listaM.h"
#include "listaP.h"
typedef struct autores tAutores;

/**
 * @brief cria uma struct vazia tAutores
 * @return um ponteiro pra struct tAutores
*/
tAutores* criaAutores();

/**
 * @brief cria e preenche a struct de autores com  todos os autores unicos
 * da playlist
 * @param listaP ponteiro da playlist 
 * @return um ponteiro pra struct tAutores
*/
tAutores* preencheAutores(tLista* listaP);

/**
 * @brief insere um novo autor na struct tAutores
 * @param autores ponteiro da struct tAutores 
 * @param nome ponteiro do nome do autor a ser inserido
*/
void insereAutores(tAutores* autores, char*nome);

/**
 * @brief libera a struct tautores
 * @param autores ponteiro pra struct tAutores
*/
void liberaAutores(tAutores* autores);

/**
 * @brief imprimie todos os nomes dos autores da struct tAutores
 * @param autores ponteiro pra struct tAutores
*/
void imprimiAutores(tAutores* autores);

/**
 * @brief verifica se ja tem o mesmo nome na struct tautores
 * @param autores ponteiro da struct tAutores 
 * @param nome ponteiro do nome do autor a ser inserido
 * @return 1 se nao tem o mesmo nome e 0 se tem
*/
int ehNomeUnico(tAutores* autores, char* nome);

/**
 * @brief aloca o uma string pra copiar uma palavra, nao esquece de liberar ela depois
 * @param palavra o ponteiro da palavra antiga
 * @return ponteiro da copia da palavra antiga
*/
char *copiaPalavra(const char *palavra);

/**
 * @brief cria um nova playlista mas so como os nome dos autores e muiscas deles
 * sendo que cada playlist representa um unico autor
 * @param autores ponteiro da struct tAutores 
 * @param listaP lista da playlist antiga
 * @return ponteiro pra nova lista de playlist refatorada 
*/
tLista* criaPlaylistFatorada(tAutores* autores, tLista* ListaP);

/**
 * @brief substuitui para cada usuaria sua listaP pou uma nova listap refatorada usando
 * a funcao criaPlaylistFatorada
 * @param listaL lista dos usuarios do spotfy
*/
void refatoraListaL(tListaL* listaL);

/**
 * @brief criar as pasta e arquivos depois de refatorar as listaP dos usuarios
 * , pra cada usuario uma pasta com seu nome e pra suas palylist e em cada palaylist os
 * arquivos das nova playlists
 * @param listaL ponteiro pra lista dos usuarios
*/
void criaPastasEArquivos(tListaL* listaL);

/**
 * @brief pegar o nome do autor de acordo com o idx pedido
 * @param autores ponteiro da struct tAuores que tem a lista dos seus nomes
 * @return o ponterio do nome do index pedido
*/
char* getNomeAutor(tAutores* autores, int idx);
#endif