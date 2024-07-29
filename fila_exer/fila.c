#include "fila.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



struct fila{
    Amostra** itens;
    int inic;// indice do primeiro elemento na fila
    int n; // numero de elementos na fila
    int tamMax; // capacidade da fila
};

tFila* iniciaFila(int tamMax){
    tFila* f = (tFila*) malloc(sizeof(tFila));
    f->itens =(Amostra**)  malloc(sizeof(Amostra*)* tamMax);
    f->inic = 0;
    f->n = 0;
    f->tamMax = tamMax;
    return f;
}

// isere um elemento na fila com prioridade
void insereFila(tFila* f, Amostra* a){
    if(f->n == f->tamMax){
        printf("Fila cheia\n");
        return;
    }

    int i,j;
    //achar a posicao com base na prioridade da amostra
    // maior idade deve ser primeiro
    for(i=0; i<f->n;i++){
        int index = (f->inic + i) % f->tamMax;
        Amostra* teste = f->itens[index];
        if(retornaIdade(teste) < retornaIdade(a)){
            break;
        }
    }
    // Mover os elementos pra achar espaço para o proximo elemento

    for(j = f->n; j>i;j--){
        int de = (f->inic+ j-1)% f->tamMax;;
        int para = (f->inic+ j)% f->tamMax;
        f->itens[para] = f->itens[de];
    }

    int pos = (f->inic +i)%f->tamMax;// essa parte calcula o indice numa lista circular
    f->itens[pos] = a;
    f->n++;
}

Amostra* retiraFila(tFila* f){
    if(f->n == 0){
        printf("Fila vazia\n");
        return NULL;
    }
    Amostra* a = f->itens[f->inic];
    f->inic = (f->inic+1) %f->tamMax;
    f->n--;
    
    return a;
}

void imprimeFila(tFila* f){
    if(!f)
        return;
    for( int i=0 ; i<f->n;i++){
        int pos = (f->inic+i)% f->tamMax;
        Amostra* a = f->itens[pos];
        imprimeAmostra(a);
    }
    printf("\n");
}

void liberaFila(tFila* f){
    if(!f)
        return;

    for( int i=0 ; i<f->n;i++){
        int pos = (f->inic+i)% f->tamMax;
        Amostra* a = f->itens[pos];
        liberaAmostra(a);
    }
    
    free(f->itens);
    free(f);

}
int getQuantidadeFila(tFila* f){
    return f->n;
}