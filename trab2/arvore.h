#ifndef ARVORE_H
#define ARVORE_H


typedef struct arv tArv;
//Cria uma árvore vazia
tArv* arvCriaVazia (void);
//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
tArv* ArvCria (int peso , int ch, tArv* e, tArv* d);
//libera o espaço de memória ocupado pela árvore a
tArv* ArvLibera (tArv* a);
//retorna true se a árvore estiver vazia e false
//caso contrário
int ArvVazia (tArv* a);
//indica a ocorrência (1) ou não (0) do caracter c
int ArvPertence (tArv* a, int ch);
//imprime as informações dos nós da árvore
void ArvImprime (tArv* a);
//retorna a quantidade de folhas da arvore
int Folhas(tArv* a);
//retorna quantas vezes o aluno aparece na arvore
int Ocorrencias(tArv* a, char ch);
// retorna altura
int Altura(tArv* a);

int getPeso(tArv* a);
int getCaractere(tArv* a);
// Função para combinar duas menores árvores em uma nova
tArv* combinaArvores(tArv* t1, tArv* t2);
#endif