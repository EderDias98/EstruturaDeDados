#include "listaSimples.h"



int main(int argc, char*argv[]){
    // criar um no bvazio
    tNo* cabeca = criaNo(4);

    insereNoPosicao(&cabeca,9,1);

    LiberaNoPosicao(&cabeca,2);

    liberaLista(&cabeca);
    // imprimiLista(&cabeca); 
    return 0;
}