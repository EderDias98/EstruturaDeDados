#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>

//Tipo matriz (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementaÁ„o do TAD


struct matriz{
    int *vet;
    int l,c;
};


/*Inicializa uma matriz de nlinhas e ncolunas
 * inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
 * output: ponteiro para a matriz inicializada
 * pre-condicao: nlinhas e ncolunas diferentes de 0
 * pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
 */
Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    Matriz * matriz = (Matriz*) calloc(1, sizeof(Matriz));
    matriz->l = nlinhas;
    matriz->c = ncolunas;
    matriz->vet = (int*) calloc(nlinhas*ncolunas,sizeof(int));
    return matriz;
}

/*Modifica o elemento [linha][coluna] da matriz mat
 * inputs: a matriz, a linha, a coluna, e o novo elemento
 * output: nenhum
 * pre-condicao: matriz mat existe, linha e coluna s„o v·lidos na matriz
 * pos-condicao: elemento [linha][coluna] da matriz modificado
 */
void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    mat->vet[linha*mat->c + coluna] = elem;
}

/*Retorna o elemento mat[linha][coluna]
 * inputs: a matriz, a linha e a coluna
 * output: elemento mat[linha][coluna]
 * pre-condicao: matriz mat existe, linha e coluna s„o v·lidos na matriz
 * pos-condicao: mat n„o È modificada
 */
int recuperaElemento(Matriz* mat, int linha, int coluna){
    return mat->vet[linha*mat->c + coluna];
}

/*Retorna o n˙mero de colunas da matriz mat
 * inputs: a matriz
 * output: o n˙mero de colunas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat n„o È modificada
 */
int recuperaNColunas (Matriz* mat){
    return mat->c;
}

/*Retorna o n˙mero de linhas da matriz mat
 * inputs: a matriz
 * output: o n˙mero de linhas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat n„o È modificada
 */
int recuperaNLinhas (Matriz* mat){
    return mat->l;
}

/*Retorna a matriz transposta de mat
 * inputs: a matriz
 * output: a matriz transposta
 * pre-condicao: matriz mat existe
 * pos-condicao: mat n„o È modificada e matriz transposta existe
 */
Matriz* transposta (Matriz* mat){

    Matriz* mat_t = inicializaMatriz(mat->c, mat->l);

    for( int i=0; i< mat->l;i++){
        for( int j=0; j<mat->c;j++){
            int elem = recuperaElemento(mat,i,j);
            modificaElemento(mat_t,j,i, elem);
        }
    }

    return mat_t;
}


 

/*Retorna a matriz multiplicacao entre mat1 e mat2
 * inputs: as matrizes mat1 e mat2
 * output: a matriz multiplicaÁ„o
 * pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1
 * correponde ao numero de linhas de mat2
 * pos-condicao: mat1 e mat2 n„o s„o modificadas e a matriz multiplicacao existe
 */
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    if(mat1->c != mat2->l){
        printf("Nao é possivel efetuar essa multiplicação!\n");
        return NULL;
    }
    Matriz* mat_m = inicializaMatriz(mat1->l,mat2->c);
    int elem=0;
    int soma=0;
    for(int i=0, j=0; i<mat1->l && j<mat2->c ; i++){
        for(int j=0; j<mat2->c;j++){
            
            //somatoria do algoritmo de multiplicacao de matrizes
            for(int s=0; s<mat1->c;s++){
                soma += recuperaElemento(mat1,i,s)*recuperaElemento(mat2,s,j);
            }

            modificaElemento(mat_m,i,j,soma);
            soma =0;// a soma recomeça para calcular o proximo elemento

        }
    }

    return mat_m;
}



/*Imprime a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: nenhuma
 */
void imprimeMatriz(Matriz* mat){
    for( int i=0; i<mat->l;i++){
        for( int j=0; j<mat->c;j++){
            printf("%d ", recuperaElemento(mat, i,j));
        }
        printf("\n");
    }
    printf("\n");
}

void imprimeLinhas (Matriz* mat, int indice);

void destroiMatriz (Matriz* mat){
    if(mat){
        if(mat->vet){
            free(mat->vet);
        }
        free(mat);
    }
}

