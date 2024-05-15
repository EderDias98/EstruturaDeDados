#include "lista.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct no{
    tAluno* aluno;
    struct no* next;
}tNo;

struct lista{
    tNo* primeiro;
    tNo* ultimo;
};

tNo* iniciaNo(tAluno* alu){
    tNo* no = (tNo*) malloc(sizeof(tNo));
    no->aluno = alu;
    no->next = NULL;
    return no;
}

tLista* iniciaLista(){
    tLista* lista = (tLista*) malloc(sizeof(tLista));
    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
}

void insereListaInicio(tLista* li, tAluno* alu){
    tNo* novoNo = iniciaNo(alu);
    //lista vazia
    if(!li->primeiro){
        li->primeiro = novoNo;
        li->ultimo = novoNo;
    }else{
        //lista nao vazia
        novoNo->next = li->primeiro;
        li->primeiro = novoNo;
    }

    return;
}

void insereListaFinal(tLista* li, tAluno* alu){
    tNo* novoNo = iniciaNo(alu);
    //listaVazia
    if(!li->primeiro){
        li->primeiro = novoNo;
        li->ultimo = novoNo;
    }else{
        li->ultimo->next = novoNo;
        li->ultimo = novoNo;
    }
    return;
}

tAluno* retiraLista(tLista* li, char* chave){
    tNo* p = li->primeiro;
    tNo* q  = NULL;
    tAluno* alu = NULL;

    while(p !=NULL && strcmp(getNomeAluno(p->aluno), chave)){
        q = p;
        p = p->next;
    }

    //lista vazia ou nao encontrou o aluno
    if(p==NULL)
        return NULL;
    
    alu = p->aluno;
    //se for unico
    if(li->primeiro == li->ultimo){
        li->primeiro = li->ultimo = NULL;
    //se encontrou no primeiro no
    }else if(p == li->primeiro){
        li->primeiro = p->next;
    //se encontrou no ultimo no
    }else if(p== li->ultimo){
        li->ultimo = q;
        li->ultimo->next = NULL;
    // caso generico
    }else{
        q->next = p->next;
    }

    free(p);

    return alu;
}

tAluno* retiraListaPosicao(tLista* li, int posi){
    tNo* p = li->primeiro;
    tNo* q  = NULL;
    tAluno* aluno = NULL;
    int i=0;
    while( i < posi && p!= NULL){
        q = p;
        p = p->next;
        i++;
    }

    if(p==NULL)
        return NULL;
    
    aluno = p->aluno;

    if(li->primeiro == li->ultimo)
        li->primeiro =li->ultimo = NULL;
    else if(p == li->primeiro)
        li->primeiro = p->next;
    else if(p == li->ultimo){
        li->ultimo = q;
        li->ultimo->next = NULL;
    }else
        q->next = p->next;
    
    free(p);

    return aluno;
    
}

void insereListaPosicao(tLista* li,tAluno* alu ,int pos){
    tNo* p = li->primeiro;
    tNo* q = NULL;
    tNo* novoNo = iniciaNo(alu);
    int i =0;
    while (p !=NULL && i<pos){
        q =p;
        p = p->next;
        i++;
    }
    
    // lista vazia
    if(!li->primeiro){
        li->primeiro = novoNo;
        li->ultimo = novoNo;
        
    }
    //se nao encontrar pos
    else if(p==NULL){
        li->ultimo->next = novoNo;
        li->ultimo = novoNo;
    }

    else if(li->primeiro  == p){
        novoNo->next = li->primeiro;
        li->primeiro = novoNo;
    }else{
        novoNo->next = p;
        q->next = novoNo;
    }
}

void imprimeLista(tLista* li){
    tNo* p = li->primeiro;
    while (p!=NULL ){
        imprimeAluno(p->aluno);
        p = p->next;
    }
}

void destroiNo(tNo* no){
    if(!no)
        return;
    
    destroiAluno(no->aluno);
    free(no);
}

void destroiLista(tLista* li){
    tNo*p = li->primeiro;
    tNo* temp = NULL;
    while(p!=NULL){
        temp = p->next;
        destroiNo(p);
        p = temp;
    }
    free(li);
}

int getTamLista(tLista* li){
    int tam =0 ;
    tNo* p = li->primeiro;
    while(p!=NULL){
        p = p->next;
        tam++;
    }
    return tam;
}