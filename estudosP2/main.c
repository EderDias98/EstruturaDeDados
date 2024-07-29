#include <stdio.h>
#include "tab.h"
#include <string.h>

int main(){

    // associar nome a idade

    tAluno** hash_table = HashInicia();

    tAluno* aluno1 = iniciaAluno(123,"Eder",6.7);
    tAluno* aluno2 = iniciaAluno(123,"Arthur",6.7);
    tAluno* aluno3 = iniciaAluno(123,"Gustavo",6.7);
    tAluno* aluno4 = iniciaAluno(123,"Matheus",6.7);
    tAluno* aluno5 = iniciaAluno(123,"Bruno",6.7);

    HashInsere(hash_table,getNomeAluno(aluno1),aluno1);
    HashInsere(hash_table,getNomeAluno(aluno2),aluno2);
    HashInsere(hash_table,getNomeAluno(aluno3),aluno3);
    HashInsere(hash_table,getNomeAluno(aluno4),aluno4);
    HashInsere(hash_table,getNomeAluno(aluno5),aluno5);

    HashImprime(hash_table);





    return 0;
}