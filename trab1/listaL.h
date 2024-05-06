#ifndef LISTA_L
#define LISTA_L
#include "listaP.h"



typedef struct NoL tNoL;
typedef struct listaL tListaL;
typedef struct amigos tAmigos;


/**
 * @brief cria uma listaL vazia com tamanho 0 
 * @return um ponteiro para listaL que tem primeiro e ultimo noL como NULL
*/
tListaL* criaListaVaziaL();

/**
 * @brief verifica se a listaL e vazia
 * @param lista ponteiro pra listaL;
 * @return 1 se a listaL e vazia e 0 se a listaL nao e vazia
*/
int ehListaVaziaL(tListaL* lista);

/**
 * @brief inseri noL no fim da listaL
 * @param lista ponteiro para a listaL
 * @param item ponteiro do item do noL a ser inserido
*/
void insereFimListaL(tListaL* lista, char* item); 

/**
 * @brief imprimi os itens da listaL
 * @param lista ponteiro para listaL
*/
void  imprimiListaL(tListaL* lista); 

/**
 * @brief libera os nosL da listaL
 * @param lista ponteiro para listaL 
*/
void liberaNosDaListaL(tListaL* lista);

/**
 * @brief libera a listaL
 * @param lista ponteiro para listaL 
*/
void liberaListaL(tListaL* lista);

/**
 * @brief insere uma string que representa um amigo
 * na struct tAmigos presente no noL
 * @param atual ponteiro do noL atual
 * @param nome um ponteiro da string do amigo 
*/
void InsereAmigoListaL(tNoL* atual, char* nome);

/**
 * @brief pega o noL do usuario presente na listaL
 * @param lista ponteiro da listaL
 * @param nome um ponteiro da string do nome do usuario que ta no noL
 * @return o ponteiro para o noL do usuario pedido 
*/
tNoL* getNoListaL(tListaL* lista, char* nome);

/**
 * @brief libera a listaP antiga do noL e coloca a listaP nova
 * @param no noL que tem a listaP
 * @param lista a listaP a ser colocada no lugar
*/
void setListaPEmL(tNoL* no, tLista* lista);

/**
 * @brief  pega tam da listaL
 * @param lista ponteiro da listaL
 * @return o tamanho da listaL
*/
int getTamL(tListaL* lista);

/**
 * @brief  pega o noL da ListaL representado pelo idx
 * @param lista ponteiro da listaL
 * @param idx o index do noL requerido
 * @return o ponteiro do noL requerido 
*/
tNoL* getNoListaIdxL(tListaL* lista,int idx);

/**
 * @brief  pega o ponteiro da listaP presente no noL
 * @param no o ponteiro do noL presente listaL
 * @return o ponteiro da listaP presente no noL
*/
tLista* getListaPDeL(tNoL* no);

/**
 * @brief  pega o ponteiro do nome representando o usuario no noL
 * @param no o ponteiro do noL que pertence a listaP
 * @return o ponteiro do nome do usuario 
*/
char* getNomeL(tNoL* no);

/**
 * @brief  cria um arquivo similaridades.txt que tem nele a quantidade de musicas
 * iguais entre dois amigos usuarios
 * @param lista ponteiro da listaL
*/
void criaSimilaridades(tListaL* listaL);
/**
 * @brief mostrar qual usuario esta primeiro colocado na listaL
 * @param lista ponteiro da listaL
 * @param nome1 ponteiro para o primeiro usuario
 * @param nom2 ponteiro para o segundo usuario
 * @return 1 se o nome1 vem primeiro e 2 se o nome2 vem primeiro
*/
int quemVemPrimeiro(tListaL* listaL, char* nome1, char* nome2);

#endif