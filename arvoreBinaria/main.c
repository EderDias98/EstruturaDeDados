#include "aluno.h"
#include "arvore.h"

int main(){
    tAluno* aluno_a = iniciaAluno(123,"Eder", 6.78);
    tAluno* aluno_b = iniciaAluno(124,"Gustavo", 7.78);
    tAluno* aluno_c = iniciaAluno(125,"Arthur", 7.77);
    tAluno* aluno_d = iniciaAluno(126,"Matheus", 7.98);
    tAluno* aluno_e = iniciaAluno(153,"Miguel", 5.78);
    tAluno* aluno_f = iniciaAluno(173,"Antonio", 4.74);

    tArv* a = ArvCria(aluno_a,ArvCria(aluno_b,arvCriaVazia(),ArvCria(aluno_d,arvCriaVazia(), arvCriaVazia())) ,
    ArvCria(aluno_c, ArvCria(aluno_e, arvCriaVazia(), arvCriaVazia()),ArvCria(aluno_f,arvCriaVazia(), arvCriaVazia())));
    
    ArvImprime(a,0);

    printf("\nQuantidade de folhas: %d\n", Folhas(a));
    return 0;
}