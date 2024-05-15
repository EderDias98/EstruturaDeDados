#include "pilha.h"


int main(){
    tLista* pilha = iniciaPilha();
    push(pilha,1);
    push(pilha,2);
    push(pilha,3);
    imprimePilha(pilha);
    pop(pilha);
    imprimePilha(pilha);
        pop(pilha);
    imprimePilha(pilha);
        pop(pilha);
    imprimePilha(pilha);


    return 0;
}