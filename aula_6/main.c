#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

Matriz* LerMatriz(){
    int l,c,elem;
    scanf("%d %d%*c",&l,&c);

    Matriz* mat = inicializaMatriz(l,c);
    
    for( int i=0; i<l;i++){
        for(int j=0; j<c;j++){
            scanf("%d%*c",&elem);
            modificaElemento(mat,i,j,elem);
        }
    }
    return mat;
}


int main(int argc, int *argv[]){


    Matriz* mat1 = LerMatriz();
    
    imprimeMatriz(mat1);

    Matriz* mat2 = LerMatriz();


    Matriz* mat1t = transposta(mat1);
    imprimeMatriz(mat1t);
    
    Matriz* mat_m = multiplicacao(mat1,mat2);
    if(mat_m){
        imprimeMatriz(mat_m);
    }

    return 0;
}