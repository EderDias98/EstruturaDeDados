#ifndef ALUNO_H
#define ALUNO_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct aluno tAluno;

tAluno* iniciaAluno(int Mat, char*nome, float Cr);
void imprimeAluno(tAluno* a);
void destroiAluno(tAluno* a);
int getMatAluno(tAluno* a);
float getCrAluno(tAluno*a);
char* getNomeAluno(tAluno* a);


#endif