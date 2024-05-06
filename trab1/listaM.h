#ifndef LISTAM_H
#define LISTAM_H
typedef struct NoM tNoM;
typedef struct listaM tListaM;

/**
 * @brief cria uma listaM vazia com tamanho 0 
 * @return um ponteiro para listaM que tem primeiro e ultimo noL como NULL
*/
tListaM* criaListaVaziaM();

/**
 * @brief verifica se a listaM e vazia
 * @param lista ponteiro pra listaM;
 * @return 1 se a listaM e vazia e 0 se a listaM nao e vazia
*/
int ehListaVaziaM(tListaM* lista);

/**
 * @brief inseri noM no fim da listaM
 * @param lista ponteiro para a listaM
 * @param item ponteiro do item do noM a ser inserido
*/
void insereFimListaM(tListaM* lista, char* item, char* desc); 

/**
 * @brief imprimi os itens da listaM
 * @param lista ponteiro para listaM
*/
void  imprimiListaM(tListaM* lista); 

/**
 * @brief libera os nosM da listaM
 * @param lista ponteiro para listaM 
*/
void liberaNosDaListaM(tListaM* lista);

/**
 * @brief libera a listaM
 * @param lista ponteiro para listaM 
*/
void liberaListaM(tListaM* lista); 

/**
 * @brief  pega tam da listaM
 * @param lista ponteiro da listaM
 * @return o tamanho da listaM
*/
int getTamM(tListaM* lista);

/**
 * @brief  pega o ponteiro do nome representando o autor/banda no noM
 * @param no o ponteiro do noM que pertence a listaM
 * @return o ponteiro do nome do autor/banda
*/
char* getAutorM(tNoM* no);

/**
 * @brief  pega o noM da ListaM representado pelo idx
 * @param lista ponteiro da listaM
 * @param idx o index do noM requerido
 * @return o ponteiro do noM requerido 
*/
tNoM* getNoListaIdxM(tListaM* lista,int idx);

/**
 * @brief pega o noM da musica presente na listaL que tenha a descricao pedida
 * @param lista ponteiro da listaM
 * @param nome um ponteiro da string do nome da descricao da musica que ta no noM
 * @return o ponteiro para o noM da musica pedida 
*/
tNoM* getNoListaM(tListaM* lista, char* nome);

/**
 * @brief  pega o ponteiro do nome representando a descricao da musica no noM
 * @param no o ponteiro do noM que pertence a listaM
 * @return o ponteiro do nome da descricao da musica
*/
char* getDescM(tNoM* no);
#endif