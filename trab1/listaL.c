#include "listaL.h"

#include "listaP.h"
#include "listaM.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAM_NOME 100;


struct amigos{
    int tam;
    char** vet; 
};

tAmigos* criaAmigos(){
    tAmigos* amigos = (tAmigos*) malloc(sizeof(tAmigos));
    amigos->tam =0;
    amigos->vet = (char**) malloc(sizeof(char*));
    return amigos;
}

void insereAmigos(tAmigos* amigos, char*nome){
    amigos->tam++;
    amigos->vet =(char**) realloc(amigos->vet, amigos->tam* sizeof(char*));
    amigos->vet[amigos->tam-1] = nome;
}

struct NoL{
    char* item;
    tAmigos* amigos;
    tLista* lista;
    struct NoL* next;
};



struct listaL{
    tNoL* primeiroNo;
    tNoL* ultimoNo;
    int tam;
};


int getTamL(tListaL* lista){
    return lista->tam;
}
tNoL* getNoListaIdxL(tListaL* lista,int idx){

    if(idx<0 || idx >lista->tam -1)
        return NULL;
    tNoL* noAtual = lista->primeiroNo;

    if(idx == 0){
        return noAtual;
    }

    for(int i=1; i<=idx;i++){
 
        noAtual = noAtual->next;
    }

    return noAtual;

}
tLista* getListaPDeL(tNoL* no){
    return no->lista;
}
void setListaPEmL(tNoL* no, tLista* lista){
    liberaListaP(no->lista);
    no->lista = lista;
}

/**
 * @brief verifica se uma lista simples e vazia
 * @param lista ponteiro pra lista;
 * @return 1 se a lista e vazia e 0 se a lista nao e vazia
*/

int ehListaVaziaL(tListaL* lista){
    if(lista->primeiroNo == NULL)
        return 1;
    else return 0;
}

void liberaAmigos(tAmigos* amigos){
    for(int i=0; i<amigos->tam;i++){
        free(amigos->vet[i]);
    }
    free(amigos->vet);
    free(amigos);
}

/**
 * @brief libera um no da lista
 * @param no ponteiro para um no da lista
*/

void liberaNoL(tNoL* no){
    free(no->item);
    liberaAmigos(no->amigos);
    // nao esquecer de liberar a lista dentro do no;
    liberaListaP(no->lista);
    free(no);
}

/**
 * @brief cria um no da lista
 * @param item pertence ao no da lista
 * @return ponteiro para o no criado
*/

tNoL* criaNoL(char* item){
    tNoL* no = (tNoL*) calloc(1, sizeof(tNoL));

    no->item = item;
    no->next = NULL;
    no->lista = criaListaVaziaP();
    no->amigos = criaAmigos();

    return no;
}

/**
 * @brief cria uma lista vazia com tamanho 0 
 * @return um ponteiro para lista que tem primeiro e ultimo no NULL
*/

tListaL* criaListaVaziaL(){
    tListaL* lista = (tListaL*) calloc(1, sizeof(tListaL));
    lista->primeiroNo = NULL;
    lista->ultimoNo = NULL;
    lista->tam =0;
    return lista;
}

/**
 * @brief inseri no no inicio da lista encadeada
 * @param lista ponteiro para a lista
 * @param item item do no a ser inserido
*/

void insereInicioListaL(tListaL* lista, char* item){
    tNoL* novoNo = criaNoL(item);

    //lista vazia
    if(ehListaVaziaL(lista))
        lista->ultimoNo = novoNo;

    // generico
    novoNo->next = lista->primeiroNo;
    lista->primeiroNo = novoNo;
    lista->tam++;
    // quando a lista e vazia o primeiro e ultimo no apontam para o mesmo no
}

/**
 * @brief inseri no no fim da lista encadeada
 * @param lista ponteiro para a lista
 * @param item item do no a ser inserido
*/

void insereFimListaL(tListaL* lista, char* item){
    tNoL* novoNo = criaNoL(item);

    //lista vazia
    if(ehListaVaziaL(lista))
        lista->primeiroNo = novoNo;
    else
        lista->ultimoNo->next = novoNo;


    //generico
 
    lista->ultimoNo = novoNo;
    lista->tam++;
}

/**
 * @brief libera primeiro item da lista encadeada
 * @param lista ponteiro para a lista
*/

void liberaPrimeiroItemListaL(tListaL* lista){
    if(ehListaVaziaL(lista))
        return;

    //generico
    tNoL* primeiroNo = lista->primeiroNo;

    //lista so tem um no
    if(lista->ultimoNo == lista->primeiroNo)
        lista->ultimoNo = NULL;

    lista->primeiroNo = lista->primeiroNo->next;
    liberaNoL(primeiroNo);
    lista->tam--;

}

/**
 * @brief libera ultimo item da lista encadeada
 * @param lista ponteiro para a lista
*/

void liberaUltimoItemListaL(tListaL* lista){
    if(ehListaVaziaL(lista))
        return;



    tNoL* noAtual = lista->primeiroNo;
    tNoL* noAnterior = NULL;

    while(noAtual->next != NULL){
        noAnterior = noAtual;
        noAtual = noAtual->next;
    }

    //so tem um item na lista
    if(noAtual == lista->primeiroNo)
        lista->primeiroNo = NULL;
    else
        noAnterior->next =NULL;

    liberaNoL(lista->ultimoNo);
   
    lista->ultimoNo = noAnterior;
    lista->tam--;
}

int compProdutoL(char* item1, char* item2){
    if(strcmp(item1, item2) == 0)
        return 1;
    else return 0;
}

/**
 * @brief libera item da lista encadeada
 * @param lista ponteiro para a lista
 * @param item item a ser liberado na lista
*/
void liberaItemListaL(tListaL* lista, char* item){
    if(ehListaVaziaL(lista))
        return;

    if(compProdutoL(lista->primeiroNo->item, item)){
        liberaPrimeiroItemListaL(lista);
        return;
    }

    if(compProdutoL(lista->ultimoNo->item, item)){
        liberaUltimoItemListaL(lista);
        return;
    }


    tNoL* noAtual = lista->primeiroNo;
    tNoL* noAnterior = NULL;

    while(noAtual->next != NULL){
        noAnterior = noAtual;
        noAtual = noAtual->next;
        if(compProdutoL(noAtual->item, item))
            break;

    }
    //se o item nao esta na lista ele alcanca o ultimo no dela;
    if(noAtual->next == NULL)
        return;

    //generico
    noAnterior->next = noAtual->next;
    liberaNoL(noAtual);
    lista->tam--;

}



tNoL* getNoListaL(tListaL* lista, char* nome){
    if(ehListaVaziaL(lista))
        return NULL;

    if(compProdutoL(lista->primeiroNo->item, nome)){
        return lista->primeiroNo;
    }

    if(compProdutoL(lista->ultimoNo->item, nome)){
        
        return lista->ultimoNo;
    }


    tNoL* noAtual = lista->primeiroNo;


    while(noAtual->next != NULL){

        noAtual = noAtual->next;
        if(compProdutoL(noAtual->item, nome)){
            return noAtual;
        }
    }

    printf("Nao tem esse nome na Lista\n");
    return NULL;
}


void InsereAmigoListaL(tNoL* atual, char* nome){
    insereAmigos(atual->amigos, nome);
}
/**
 * @brief insere item na lista encadeada no index dado
 * @param lista ponteiro para a lista
 * @param item item a ser liberado na lista
 * @param  idx posicao em que sera inserido o item na lista
*/

void insereItemListaIdxL(tListaL* lista,char* item ,int idx){

    if(idx<0 || idx >lista->tam)
        return;

    if(idx == lista->tam){
        insereFimListaL(lista,item);
        return;
    }

    if(idx == 0){
        insereInicioListaL(lista,item);
        return;
    }

    tNoL* novoNo = criaNoL(item);

    tNoL* noAtual = lista->primeiroNo;
    tNoL* noAnterior = NULL;

    for(int i=1; i<=idx;i++){
        noAnterior = noAtual;
        noAtual = noAtual->next;
    }

    //generico
    novoNo->next = noAtual;
    noAnterior->next = novoNo;
    lista->tam++;

}

/**
 * @brief libera item na lista encadeada no index dado
 * @param lista ponteiro para a lista
 * @param item item a ser liberado na lista
 * @param  idx posicao em que sera liberado o item na lista
*/
void liberaItemListaIdxL(tListaL* lista, int idx){

    if(idx<0 || idx >=lista->tam)
        return;
    
    tNoL* noAtual = lista->primeiroNo;
    tNoL* noAnterior = NULL;

    for(int i=1; i<=idx;i++){
        noAnterior = noAtual;
        noAtual = noAtual->next;
    }

    // o index e zero
    if(noAtual == lista->primeiroNo){
        liberaPrimeiroItemListaL(lista);
        return;    
    }

    if(noAtual == lista->ultimoNo){
        lista->ultimoNo = noAnterior;
    }

    noAnterior->next = noAtual->next;
    liberaNoL(noAtual);
    lista->tam--;
    
}

/**
 * @brief imprimi os itens da lista encadeada
 * @param lista ponteiro para lista 
*/
void  imprimiListaL(tListaL* lista){

    if(ehListaVaziaL(lista))
        return;
    tNoL* noAtual = lista->primeiroNo;
    for (int i = 0; i < lista->tam; i++){
        printf("%s:\n", noAtual->item);
        for(int j=0; j< noAtual->amigos->tam;j++){
            printf("%s ", noAtual->amigos->vet[j]);
        }
        imprimiListaP(noAtual->lista);
        noAtual = noAtual->next;
        printf("\n");
    }
    printf("\n");
}

/**
 * @brief libera os nos da lista encadeada
 * @param lista ponteiro para lista 
*/

void liberaNosDaListaL(tListaL* lista){
    if(ehListaVaziaL(lista))
        return;

    tNoL* noAtual = lista->primeiroNo;
    tNoL* noAnterior = NULL;

    while(noAtual->next != NULL){
        noAnterior = noAtual;
        noAtual = noAtual->next;
        liberaNoL(noAnterior);
    }
    
    liberaNoL(noAtual);
    lista->tam=0;
}

/**
 * @brief libera a lista encadeada
 * @param lista ponteiro para lista 
*/

void liberaListaL(tListaL* lista){
    if(!lista)
        return;
    liberaNosDaListaL(lista);
    free(lista);
}

char* getNomeL(tNoL* no){
    return no->item;
}
// 0 1 2 3 4 5
int ehMusicasIguais(tNoM* no1, tNoM* no2){
    if(strcmp(getAutorM(no1), getAutorM(no2))==0){
        if(strcmp(getDescM(no1), getDescM(no2))==0){
            return 1;
        }
    }

    return 0;
}

int contMusicasIguais(tNoL* no1, tNoL* no2){
    tLista* listaP1 = getListaPDeL(no1);
    tLista* listaP2 = getListaPDeL(no2);
    tNo* noP1;
    tNo* noP2;
    tListaM* listaM1;
    tListaM* listaM2;
    tNoM* noM1;
    tNoM* noM2;
    int qtd=0;
    int flagR=0;
    //pra cada musica de p1 ver se tem uma musica iqual em p2;
    for(int i=0; i<getTamP(listaP1);i++){

        noP1 = getNoListaIdxP(listaP1,i);
        listaM1 = getListaMDeP(noP1);
        
        for(int j=0; j<getTamM(listaM1);j++){
            noM1 = getNoListaIdxM(listaM1,j);
            flagR = 0;
            for(int k=0; k<getTamP(listaP2);k++){

                noP2 = getNoListaIdxP(listaP2,k);
                listaM2 = getListaMDeP(noP2);
                for(int l=0; l<getTamM(listaM2);l++){
                    noM2 = getNoListaIdxM(listaM2,l);
                    if(ehMusicasIguais(noM1, noM2) && !flagR){
                        qtd++;
                        flagR =1;
                    }
                }
            }
        }
    }
    return qtd;
}


int quemVemPrimeiro(tListaL* listaL, char* nome1, char* nome2){
    tNoL* noL;
    for(int i=0; i<listaL->tam;i++){
        noL = getNoListaIdxL(listaL,i);
        if(strcmp(nome1, noL->item)==0)
            return 1;
        if(strcmp(nome2,noL->item) == 0)
            return 2;
    }
    return 3;
}


void criaSimilaridades(tListaL* listaL){

    char nome_arquivo[200] = {'\0'};
    sprintf(nome_arquivo,"SaidaM/similaridades.txt");
    FILE *arquivo = fopen(nome_arquivo, "w");

    // Verificar se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        fprintf(stderr, "Erro: Falha ao criar o arquivo \"%s\".\n", nome_arquivo);            
    }

    tNoL* noL;
    tNoL* noLA;
    int qtd=0;
    // procurar todo mundo
    for(int i=0; i<listaL->tam;i++){
        noL = getNoListaIdxL(listaL,i);
        if(noL->amigos->tam){
            for(int j=0; j<noL->amigos->tam;j++){
                noLA = getNoListaL(listaL, noL->amigos->vet[j]); 
                qtd = contMusicasIguais(noL,noLA);
                
                fprintf(arquivo,"%s;%s;%d\n", noL->item, noL->amigos->vet[j],qtd);
            }
        }
    

    }
    fclose(arquivo);
}