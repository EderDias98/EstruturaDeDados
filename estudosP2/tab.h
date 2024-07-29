#ifndef TAB_H
#define TAB_H
#define TAB 10
#include "aluno.h"



int HashFunc(char* chave);

tAluno** HashInicia();
tAluno* HashBusca(tAluno **hash_table,char* chave);

void HashInsere(tAluno **hash_table, char* chave, tAluno* aluno);

void HashFree(tAluno **hash_table);

void HashImprime(tAluno** hash_table);
#endif