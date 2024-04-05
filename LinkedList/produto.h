#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct produto tProduto;


tProduto* criaProduto(char* nome, int cod, float preco);

/**
 *@brief liberar  a memoria do produto
 *@param produtoV ponteiro void do produto
*/

void liberaProduto(void* produtoV);

/**
 *@brief imprime o produto
 *@param produtoV ponteiro void do produto
*/
void imprimiProduto(void* produtoV);

/**
 *@brief imprime o produto
 *@param produto1V ponteiro void do produto1
 *@param produt2V ponteiro void do produto2
 *@return 1 caso sao iguais 0 caso contrário 
*/

int compProduto(const void* produto1V, const void* produto2V);


#endif