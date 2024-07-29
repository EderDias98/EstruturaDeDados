#include "tab.h"



tAluno** HashInicia(){
    tAluno** hash = calloc(TAB,sizeof(tAluno*));
    return hash;
}

int HashFunc(char* chave){
    int total=*chave;
    while(*chave++){
        total += *chave;        
    }
    total %= TAB;
    return total;
}

tAluno* HashBusca(tAluno** hash_table,char* chave){
    int idx  = HashFunc(chave);
    while(hash_table[idx]!=NULL){
        if (strcmp(chave, getNomeAluno(hash_table[idx]))==0)
            return hash_table[idx];
        idx = (idx+1)%TAB; 
    }
    return NULL;
}

void HashInsere(tAluno** hash_table, char* chave, tAluno* aluno){
    int idx  = HashFunc(chave);

    while(hash_table[idx]!=NULL){
        if (strcmp(chave, getNomeAluno(hash_table[idx]))==0)
            break;
        idx = (idx+1) %TAB;
    }
    // posso inserir um novo elemento ou modificar um já existente
    if(hash_table[idx]== NULL){
        hash_table[idx] = aluno;
    }else{
        destroiAluno(hash_table[idx]);
        hash_table[idx] = aluno;
    }
}

void HashFree(tAluno** hash_table){
    for(int i=0; i<TAB;i++){
        destroiAluno(hash_table[i]);
    }
    free(hash_table);
}

void HashImprime(tAluno** hash_table){
    for(int i=0; i<TAB;i++){
        imprimeAluno(hash_table[i]);
    }
}