#include "tabelaRot.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAB_MAX 200

struct pacote{
    char destination[200];
    char nextHope[200];
};


PACOTE** TabelaHotInicia(){
    PACOTE** pac = (PACOTE**) calloc(TAB_MAX, sizeof(PACOTE*));
    return pac;
}

int TabelaRotFunc(char* destinarion){
    int total=0;
    for(int i=0; destinarion[i]!= '\0';i++ ){
        total += destinarion[i];
    }
    return total;
}

char* TabelaRotBusca(PACOTE** hash, char* destination){
    int h = TabelaRotFunc(destination);
    while(hash[h]!=NULL){
        if(strcmp(hash[h]->destination, destination)==0)
            return hash[h]->nextHope;
        h = (h+1) % TAB_MAX;
    }
    return NULL;
}

void TabelaRotInsere(PACOTE** hash, char* destination, char* nextHop){
    int h = TabelaRotFunc(destination);
 
    while(hash[h] != NULL){
        if(strcmp(hash[h]->destination, destination) == 0)
            break;      
        h = (h+1) % TAB_MAX;
    }
    if(hash[h]==NULL){
        PACOTE* pac =(PACOTE*) calloc(1, sizeof(PACOTE));
        hash[h] = pac;
    }
    strcpy(hash[h]->destination, destination);
    strcpy(hash[h]->nextHope, nextHop);

}
