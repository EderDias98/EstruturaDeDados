#include "arvoresAvl.h"
#include <stdio.h>


int main() {
    tAvlArv* raiz = NULL;

    // Casos de teste
    int valores[] = {5, 20,7, 23, 15, 25, 7,3 ,80,54};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        raiz = AvlArvInsere(raiz, valores[i]);
        printf("Árvore após inserir %d:\n", valores[i]);
        AvlArvImprime(raiz, 0);
        printf("\n");
    }
    return 0;
}