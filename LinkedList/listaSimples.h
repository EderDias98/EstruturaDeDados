#ifndef LISTA_SIMPLES_H
#define LISTA_SIMPLES_H

typedef struct listaSimples tLista;
typedef struct no tNo;




/**
 * @brief Responde se a lista é vazia
 * @param lista endereco da lista
 * @param no ponteiro para o no liberado
*/

void liberaNo(tLista* lista, tNo* no);



/**
 * @brief Responde se a lista é vazia
 * @param lista endereco da lista
 * @return 1 pra lista vazia e 0 pra lista nao vazia;
*/
int EhListaVazia(tLista* lista);


/**
 * @brief Cria uma lista vazia
 * @param freeFun funçao pra liberar o iten da lista
 * @param comp funcao pra comparar os itens da lista
 * @return ponteiro para uma lista vazia
*/

tLista* criaLista(void (*freeFun)(void *), int (*comp)(const void *, const void *), void(*printFun)(void*));


/**
 * @brief Cria novo no da Lista
 * @return ponteiro para o novo no
*/

tNo* criaNovoNo();




/**
 * @brief Adicionar um item no inicio da lista
 * @param lista endereco da lista
 * @param item endereco do item
*/

void AdInicioLista(tLista *lista, void *item);
  

/**
 * @brief Adicionar um item no Fim da lista
 * @param lista endereco da lista
 * @param item endereco do item
*/

void AdFimLista(tLista *lista, void *item);


/**
 * @brief deletar o primeiro item da lista
 * @param lista endereco da lista
*/

void deletaInicioLista(tLista* lista);
 


/**
 * @brief deletar o ultimo item da lista
 * @param lista endereco da lista
*/

void deletaFimLista(tLista* lista);


/**
 * @brief retira item da lista
 * @param lista ponteiro pra lista
 * @param item ponteiro do item
 * @return 1 caso sucesso e 0 caso fracasso
*/

int retiraItemLista(tLista* lista, void* item);


#endif