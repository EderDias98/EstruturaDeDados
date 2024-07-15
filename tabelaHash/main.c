#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


int main(int argc, char*argv[]){

    if(argc>2){
        printf("Quantidade de argumentos esta errada!\n");
        exit(-1);
    }

    FILE* f = fopen(argv[1], "r");
    if(!f){
        printf("Erro em abrir o arquivo\n");
        exit(-1);
    }
    
    PALAVRA** hash = HashInicia();
    
    char str[TAM_PAL] = {'\0'};
    while(PalavraLe(f,str)){
        HashInsere(hash,str);
    }

    int tam = HashQuantidade(hash);
    PALAVRA** vet = PalavraCriaVetorOrdenado(hash,tam);
    PalavraImprimeVet(vet,tam);


    return 0;
}