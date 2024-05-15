#include "aluno.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct aluno{
    int Mat;
    float Cr;
    char* nome;
};
char *strdup(const char *str) {
    size_t len = strlen(str) + 1;
    char *dup = malloc(len);
    if (dup) {
        memcpy(dup, str, len);
    }
    return dup;
}

tAluno* iniciaAluno(int Mat, char*nome, float Cr){
    tAluno* aluno = (tAluno*) malloc(sizeof(tAluno));
    aluno->Cr = Cr;
    aluno->Mat = Mat;
    aluno->nome = strdup(nome);
    return aluno;
}
void imprimeAluno(tAluno* a){
    printf("%d %.2f %s\n", a->Mat, a->Cr, a->nome);
}
void destroiAluno(tAluno* a){
    if(!a)
        return;
    free(a->nome);
    free(a);
}
int getMatAluno(tAluno* a){
    return a->Mat;
}
float getCrAluno(tAluno*a){
    return a->Cr;
}
char* getNomeAluno(tAluno* a){
    return a->nome;
}