#ifndef LISTA_D
#define LISTA_D

typedef struct No tNo;



int tamLista(tNo *no);

tNo* criaNo(int item);


/**
 * @brief insere o  no na posicao da lista encadeada, se quero inserir no comeco da lista
 * uso a posicao 1 e se for no final uso a posicao tam+1;
 * @param cabeca e um endereco que armazena o ponteiro da cabeca da lista
 * @param item o item da lista
 * @param posicao a posicao da lista indo de 1 a tam+1;
*/

void insereNoPosicao(tNo** cabeca, int item , int posicao);

void LiberaNoPosicao(tNo** cabeca, int posicao);
   

void liberaLista(tNo** cabeca);
  
void imprimiLista(tNo** cabeca);

void insereItemInicio(tNo** cabeca, int item);

void insereItemFinal(tNo** cabeca, int item);

void LiberaIteminicio(tNo** cabeca);

void LiberaItemFinal(tNo** cabeca);

#endif