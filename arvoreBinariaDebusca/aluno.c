#include "aluno.h"


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
    printf("%.2f %s\n",a->Cr, a->nome);
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

int ehMaiorAluno(tAluno* a1, tAluno* a2){
    if(a1->Cr>a2->Cr){
        return 1;
    }else return 0;
    
}