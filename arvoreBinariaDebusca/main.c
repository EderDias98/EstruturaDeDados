#include "aluno.h"
#include "arvoreDeBusca.h"

int main(){
    tAluno* aluno_a = iniciaAluno(123,"Eder", 6.78);
    tAluno* aluno_b = iniciaAluno(124,"Gustavo", 7.78);
    tAluno* aluno_c = iniciaAluno(125,"Arthur", 7.77);
    tAluno* aluno_d = iniciaAluno(126,"Matheus", 7.98);
    tAluno* aluno_e = iniciaAluno(153,"Miguel", 9);
    tAluno* aluno_f = iniciaAluno(173,"Antonio", 10);

    tArv* raiz = ArvoreDeBuscaCria();
    raiz = ArvoreDeBuscaInsere(raiz,aluno_a);
    raiz = ArvoreDeBuscaInsere(raiz,aluno_b);
    raiz = ArvoreDeBuscaInsere(raiz,aluno_c);
    raiz = ArvoreDeBuscaInsere(raiz,aluno_d);
    raiz = ArvoreDeBuscaInsere(raiz,aluno_e);
    raiz =  ArvoreDeBuscaInsere(raiz,aluno_f);


    
    ArvoreDeBuscaImprime(raiz,0);
    printf("\n\n");
    // imprimeAluno(ArvoreDeBuscaGetAluno(ArvoreDeBuscaBusca(raiz, aluno_f)));    


    // raiz = ArvoreDeBuscaRemove(raiz,aluno_d);
    // raiz = ArvoreDeBuscaRemove(raiz,aluno_a);
    // ArvoreDeBuscaImprime(raiz,0);
    // ArvoreDeBuscaLibera(raiz);
    raiz =  ArvoreDeBuscaBalancea(raiz);
    ArvoreDeBuscaImprime(raiz,0);
    return 0;
}