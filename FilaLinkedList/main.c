#include "fila.h"

int main(){

    tLista* fila = iniciaFila();
    insereFiLa(fila,1);
    // insereFiLa(fila,2);
    // insereFiLa(fila,3);
    // insereFiLa(fila,4);
    // insereFiLa(fila,5);

    imprimeFila(fila);
    retiraFila(fila);
      imprimeFila(fila);

      destroiFila(fila);


    return 0;
}