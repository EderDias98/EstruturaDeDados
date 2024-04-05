#include "lista.h"
#include "produto.h"



int main(){
    tLista* lista  = criaListaVazia();


    tProduto* produto1 = criaProduto("boliche",0,12.00);
    tProduto* produto2 = criaProduto("bola",1,15.00);
    tProduto* produto3 = criaProduto("faca",2,14.60);
    tProduto* produto4 = criaProduto("chuteira",3,13.10);
    tProduto* produto5 = criaProduto("barra",4,22.00);
    tProduto* produto6 = criaProduto("cacal",5,21.00);

    insereFimLista(lista,produto1);
    insereFimLista(lista,produto2);
    insereFimLista(lista,produto3);
    insereFimLista(lista,produto4);
    insereFimLista(lista, produto5);
    
    liberaItemLista(lista, produto6);

    insereItemListaIdx(lista,produto6,4);

    liberaItemListaIdx(lista,5);

    imprimiLista(lista);
  
    liberaLista(lista);

    return 0;
}