#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct produto{
    char *nome;
    float valor;
};

typedef struct produto tProduto;


struct item{
    int quantidade;
    tProduto* produto;
};

typedef struct item tItem;

struct estoque{
    int valorEstoque;
    tItem** vetorItens;
    int tamI;
};

typedef struct estoque tEstoque;

struct filial{
    char *nome;
    tEstoque* estoque;

};

typedef struct filial tFilial;

struct supermercado{
    char *nome;
    tFilial** vetorFilial;
    int tamF; 
    int ValorTotalEstoque;
};

typedef  struct supermercado tSupermecado;

tProduto* CriarELerProduto(){
    char nome[200];
    float valor;
    printf("\nDigite o nome do produto:\n");
    scanf("%[^\n]%*c", nome);


    tProduto* produto = (tProduto*) calloc(1,sizeof(tProduto));
    produto->nome = strdup(nome);

    printf("\nDigite o valor do produto:\n");
    scanf("%f%*c", &valor);
    produto->valor = valor;
    
    return produto;

}

tItem * CriarELerItens(){
    int qtd;
    printf("\nDigite a quantidade relacionado ao item:\n");
    scanf("%d%*c", &qtd);

    tItem* item = (tItem*) calloc(1, sizeof(tItem));
    item->quantidade = qtd;

    item->produto = CriarELerProduto();
    return item;
}

tEstoque* CriarELerEstoque(){
    int valor,tam;
    printf("\nDigite o valor do estoque:\n");
    scanf("%d%*c", &valor);

    tEstoque* estoque = (tEstoque*) calloc(1,sizeof(tEstoque));

    estoque->valorEstoque = valor;
    printf("\nDigite a quantidades de itens do estoque:\n");
    scanf("%d%*c", &tam);
    estoque->tamI = tam;

    estoque->vetorItens = (tItem**) calloc(estoque->tamI, sizeof(tItem*));
    for(int i=0; i< estoque->tamI;i++){
        estoque->vetorItens[i] = CriarELerItens();
    }

    return estoque;
}

tFilial* CriarELerFilial(){
    char nome[200];
    printf("\nDigite o nome da Filial:\n");
    scanf("%[^\n]%*c", nome);

    
    tFilial* filial =(tFilial*) calloc(1,sizeof(tFilial));
    filial->nome = strdup(nome);
    filial->estoque = CriarELerEstoque();

    return filial; 
} 


tSupermecado* CriarELerSupermercado(){
    char nome[200];
    printf("\nDigite o nome do Supermercado:\n");
    scanf("%[^\n]%*c", nome);

    tSupermecado* supermercado = (tSupermecado*) calloc(1, sizeof(tSupermecado));

    supermercado->nome = strdup(nome);

    int tam;
    printf("\nDigite a quantidade de filiais:\n");
    scanf("%d%*c", &tam);
    supermercado->tamF = tam;
    supermercado->vetorFilial = (tFilial**) calloc(supermercado->tamF, sizeof(tFilial*));

    for(int i=0; i< supermercado->tamF;i++){
        supermercado->vetorFilial[i] =  CriarELerFilial(); 
    }

    return supermercado;
}

// Nome: Carone, Estoque Total: 184500
//              Filial: Jardim Camburi
//              Estoque: 23000
//                  Item: Leite Integral Selita, valor unitário: 10, quantidade: 200
//                  Item: Presunto de Parma, valor unitário: 50, quantidade: 300
//                  Item: Queijo, valor unitário: 30, quantidade: 200
//              Filial: Jardim da Penha
//              Estoque: 161500
//                  Item: Biscoito, valor unitário: 5, quantidade: 2000
//                  Item: Presunto de Parma, valor unitário: 50, quantidade: 3000
//                  Item: Carne de Sol, valor unitário: 30, quantidade: 50

void ImprimirSupermercado(tSupermecado* supermercado){
    printf("Nome: %s, Estoque Total: %d\n", supermercado->nome, supermercado->ValorTotalEstoque);
    for(int i=0; i< supermercado->tamF;i++){
        printf("    Filial: %s\n", supermercado->vetorFilial[i]->nome);
        printf("    Estoque: %d\n", supermercado->vetorFilial[i]->estoque->valorEstoque);
        for(int j=0; j< supermercado->vetorFilial[i]->estoque->tamI;j++){
            printf("        Item: %s, calor unitário: %.0f. quantidade: %d\n", supermercado->vetorFilial[i]->estoque->vetorItens[i]->produto->nome,
            supermercado->vetorFilial[i]->estoque->vetorItens[i]->produto->valor,supermercado->vetorFilial[i]->estoque->vetorItens[i]->quantidade);
        }
    }

}

int main(int argc, int *argv[]){
    tSupermecado* supermercado = CriarELerSupermercado();


    return 0;
}