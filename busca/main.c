#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM_MAX 100000


int comp(void * a, void * b){
    int *a1 = (int*) a;
    int *b1 = (int*) b;

    return *a1 - *b1;
}


void imprimiVet(int* vet, int tam){
    printf("\n");
    for( int i=0; i<tam;i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void troca(int*vet,int i, int j){
    int temp = vet[i];
    vet[i] = vet[j];
    vet[j] = temp;
}

void ordenacaoBolha(int* vet, int tam, int (*cmp) ( void* ,void*)){

    for(int i=0; i<tam-1 ; i++){
        for(int j=0; j< tam-1-i;j++){
           
            if(cmp(&vet[j],&vet[j+1]) >=1){
                troca(vet,j, j+1);
            }
        }
   
    }


}

int buscaBinaria(int* vet, int tam, int valor){
    int inicio =0;
    int fim = tam-1; 
    while(inicio<fim){
        int meio = (inicio+fim)/2;
        if(vet[meio] == valor)
            return valor;
        if(valor <= vet[meio])
            fim = meio-1;
        else inicio = meio+1;
    }
    return -1;
}

int particionaVetor(int inicio, int fim, int*vet){
    int pivo = vet[fim];
    int j = inicio-1;
    for(int i = inicio;i<fim;i++){
        if(vet[i]<=pivo){
            j++;
            troca(vet,j,i);
        }
    }
    troca(vet,j+1,fim);
    return j+1;
}

void quickSorte(int *vet, int inicio, int fim){
    if(inicio<fim){
        int pivo = particionaVetor(inicio,fim,vet);
        quickSorte(vet,inicio, pivo-1);
        quickSorte(vet,pivo+1,fim);
    }
}


int main(){
    int vet[TAM_MAX] = {0};
    srand(time(NULL));
    
    for(int i=0; i<TAM_MAX;i++){
        vet[i] = (rand()% 100) +1;
    }

    // imprimiVet(vet, TAM_MAX);
    int (*cmp) (void*,void*) = comp;
    // ordenacaoBolha(vet,TAM_MAX,cmp);
    quickSorte(vet,0,TAM_MAX-1);
    imprimiVet(vet,TAM_MAX);
    // printf("\n#%d#\n", buscaBinaria(vet,TAM_MAX,10));
    return 0;
}