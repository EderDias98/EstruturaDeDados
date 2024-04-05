#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto{
    char* nome;
    int cod;
    float preco;
};


char* strdup(const char* str) {
    // Verifica se a string fornecida é NULL
    if (str == NULL) {
        return NULL;
    }

    // Calcula o comprimento da string
    int tam = strlen(str) + 1;

    // Aloca memória para a cópia da string
    char* copia = (char*)malloc(tam * sizeof(char));

    // Verifica se a alocação de memória foi bem-sucedida
    if (copia == NULL) {
        return NULL; // Em caso de falha, retorna NULL
    }

    // Copia a string para a memória alocada
    memcpy(copia, str, tam);

    // Retorna a cópia da string
    return copia;
} 

/**
 *@brief cria produto 
 *@param nome ponteiro do nome do produto
 *@param cod codigo do produto
 *@param preco preco do produto
 *@return produto criado 
*/

tProduto* criaProduto(char* nome, int cod, float preco){
    tProduto* produto = (tProduto*) calloc(1, sizeof(tProduto));

    produto->nome = strdup(nome);
    produto->cod = cod;
    produto->preco = preco;

    return produto;

}
/**
 *@brief liberar  a memoria do produto
 *@param produtoV ponteiro void do produto
*/

void liberaProduto(void* produtoV){
    tProduto* produto = (tProduto*) produtoV;
    free(produto->nome);
    free(produto);
}
/**
 *@brief imprime o produto
 *@param produtoV ponteiro void do produto
*/
void imprimiProduto(void* produtoV){
    tProduto* produto = (tProduto*) produtoV;
    printf("%s %d %.2f\n", produto->nome, produto->cod, produto->preco);
}
/**
 *@brief imprime o produto
 *@param produto1V ponteiro void do produto1
 *@param produt2V ponteiro void do produto2
 *@return 1 caso sao iguais 0 caso contrário 
*/

int compProduto(const void* produto1V, const void* produto2V){
    tProduto* produto1 = (tProduto*) produto1V;
    tProduto* produto2 = (tProduto*) produto2V;

    if(strcmp(produto1->nome, produto2->nome) == 0)
        return 1;
    if(produto1->cod == produto2->cod)
        return 1;

    return 0;
}
