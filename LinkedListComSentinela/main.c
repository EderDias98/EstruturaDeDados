#include "lista.h"
#include <stdio.h>
int main(){

    tAluno* aluno1 = iniciaAluno(1,"renata",9.8);
    tAluno* aluno2 = iniciaAluno(2,"ricardo",9.6);
    tAluno* aluno3 = iniciaAluno(3,"riobaldo",9.7);
    

    tLista* lista  = iniciaLista();

    insereListaPosicao(lista,aluno1,0);
        insereListaPosicao(lista,aluno2,0);

            insereListaPosicao(lista,aluno3,0);

    retiraListaPosicao(lista,2);
    imprimeLista(lista);


    return 0;
}