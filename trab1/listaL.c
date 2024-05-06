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


void liberaNoL(tNoL* no){
    free(no->item);
    liberaAmigos(no->amigos);
    // nao esquecer de liberar a lista dentro do no;
    liberaListaP(no->lista);
    free(no);
}


tNoL* criaNoL(char* item){
    tNoL* no = (tNoL*) calloc(1, sizeof(tNoL));

    no->item = item;
    no->next = NULL;
    no->lista = criaListaVaziaP();
    no->amigos = criaAmigos();

    return no;
}



tListaL* criaListaVaziaL(){
    tListaL* lista = (tListaL*) calloc(1, sizeof(tListaL));
    lista->primeiroNo = NULL;
    lista->ultimoNo = NULL;
    lista->tam =0;
    return lista;
}





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





int compProdutoL(char* item1, char* item2){
    if(strcmp(item1, item2) == 0)
        return 1;
    else return 0;
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



void liberaListaL(tListaL* lista){
    if(!lista)
        return;
    liberaNosDaListaL(lista);
    free(lista);
}

char* getNomeL(tNoL* no){
    return no->item;
}

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