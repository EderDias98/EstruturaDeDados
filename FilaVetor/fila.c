#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#define TAM 10
struct fila{
    int ini; //indice do inicio da fila
    int n; // numero de elementos da fila
    int vet[TAM];
};

tFila* iniciaFila(){
    tFila* fila = (tFila*) malloc(sizeof(tFila));
    fila->n =0;
    fila->ini=0;
    return fila;
}

void insereFila(tFila* f, int n){
    if(!f || f->n == TAM){
        printf("fila cheia\n");
        return;
    }
    
    int pos = (f->ini+ f->n) % TAM;
    f->vet[pos] = n;
    f->n++;
}

int retiraFila(tFila* f){
    if(!f || f->n == 0){
        printf("fila vazia\n");
        return -1;
    }
    int n = f->vet[f->ini];
    // calcula o próximo indice da fila
    f->ini = (f->ini+1) % TAM;
    f->n--;
    return n;
}

void imprimeFila(tFila* f){
    int pos = 0;
    for(int i=0; i< f->n;i++){
        pos = (f->ini+i)%TAM;
        printf("%d ", f->vet[pos]);
        
    }
}
void destroiFila(tFila* f){
    free(f );
}