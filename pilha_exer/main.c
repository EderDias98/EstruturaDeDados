#include "pilhaDupla.h"
#include "pilhaN.h"


int main(){

    tGato* g1 = inicGato("eder1",1);
    tGato* g2 = inicGato("eder2",1);
    tGato* g3 = inicGato("eder3",1);
    tPilha* p = iniciaPilhaN();
    
    popN(p,2);

    imprimeN(p,2);

    return 0;
}