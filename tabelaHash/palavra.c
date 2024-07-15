#include "palavra.h"
#include "string.h"
#include <ctype.h>
#include "hash.h"
PALAVRA* PalavraInicializa(char*str){
    PALAVRA* pal = calloc(1, sizeof(PALAVRA));
    strcpy(pal->p,str);
    pal->frq = 0;
    pal->prox = 0;
    return pal;
}

int PalavraLe(FILE* f, char*p){
    //pular os vazios
    int c;
    while((c = fgetc(f)) != EOF){
        if(isalpha(c))
            break;
    }

    if(c == EOF)
        return 0;

    int i=0;
    p[i++] = c;
    while((c = fgetc(f)) != EOF && isalpha(c))
        p[i++] = c;
    p[i] = '\0';

    return 1;
}

int comp(const void* a,const void* b){
    PALAVRA** pal_a = (PALAVRA**) a;
    PALAVRA** pal_b = (PALAVRA**) b;
    //orderna em decresecte
    if((*pal_a)->frq > (*pal_b)->frq ){
        return -1;
    }else if((*pal_a)->frq < (*pal_b)->frq ){
        return 1;
    }else return strcmp((*pal_a)->p,(*pal_b)->p);
}


PALAVRA** PalavraCriaVetorOrdenado(PALAVRA** hash, int tam){
    PALAVRA** vet = (PALAVRA**) calloc(tam, sizeof(PALAVRA*));
    int j=0;
    for(int i=0; i<TAM_TAB;i++){
        PALAVRA* pal = hash[i];
        // colocar todas as palavras no vetor
        while(pal!= NULL){
            vet[j++] = pal;
            pal = pal->prox;
        }
    }

    // ordenar vetor
    qsort(vet, tam,sizeof(PALAVRA*),comp);

    return vet;

}

void PalavraImprimeVet(PALAVRA** vet, int tam){
    printf("Imprimir Lista de palavras:\n");
    for(int i=0; i<tam;i++){
        printf("%s frq: %d\n",vet[i]->p,vet[i]->frq);
    }
}