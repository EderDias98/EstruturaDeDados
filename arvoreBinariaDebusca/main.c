#include "aluno.h"
#include "arvoreDeBusca.h"

int main(){
    tAluno* aluno_a = iniciaAluno(123,"Eder", 6.78);
    tAluno* aluno_b = iniciaAluno(124,"Gustavo", 7.78);
    tAluno* aluno_c = iniciaAluno(125,"Arthur", 7.77);
    tAluno* aluno_d = iniciaAluno(126,"Matheus", 7.98);
    tAluno* aluno_e = iniciaAluno(153,"Miguel", 5.78);
    tAluno* aluno_f = iniciaAluno(173,"Antonio", 4.74);

    tArv* raiz = criaArvoreBusca();
    insereNaArvoreBusca(&raiz,aluno_a);
    insereNaArvoreBusca(&raiz,aluno_b);
    insereNaArvoreBusca(&raiz,aluno_c);
    insereNaArvoreBusca(&raiz,aluno_d);
    insereNaArvoreBusca(&raiz,aluno_e);
    insereNaArvoreBusca(&raiz,aluno_f);


    
    ArvImprime(raiz,0);


    return 0;
}