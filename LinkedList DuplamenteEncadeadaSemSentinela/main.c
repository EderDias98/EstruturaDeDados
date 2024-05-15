#include "listaDupla.h"
#include <stdlib.h>
#include <stdio.h>



int main(int argc, char*argv[]){
    // criar um no bvazio
    tNo* cabeca =NULL;
    insereItemInicio(&cabeca,2);
   insereItemInicio(&cabeca,6);
    LiberaItemFinal(&cabeca);
    LiberaItemFinal(&cabeca);


    imprimiLista(&cabeca); 
    return 0;
}