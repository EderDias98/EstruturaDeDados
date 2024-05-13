#include "fila.h"

int main(){
    tFila* f = iniciaFila();
    insereFila(f,3);
    insereFila(f,6);
    insereFila(f,5);
    insereFila(f,1);
    insereFila(f,7);
    insereFila(f,9);

    retiraFila(f);

    retiraFila(f);

    retiraFila(f);

    

    insereFila(f,2);
    insereFila(f,2);
    insereFila(f,2);
    insereFila(f,2);
    insereFila(f,2);
    insereFila(f,2);
    insereFila(f,2);
     

    imprimeFila(f);

    return 0;
}