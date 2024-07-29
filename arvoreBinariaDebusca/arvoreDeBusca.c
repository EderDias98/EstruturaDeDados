#include "arvoreDeBusca.h"

struct arv{
    tAluno* aluno;
    struct arv* dir;
    struct arv* esq;
};

tAluno* ArvoreDeBuscaGetAluno(tArv* raiz){
    return raiz->aluno;
}
//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
tArv* ArvoreDeBuscaCria(){
    return NULL;
}



tArv* ArvoreDeBuscaInsere(tArv* raiz, tAluno* aluno){
    if(raiz != NULL){

        if(ehMaiorAluno(aluno,raiz->aluno)<=0){
           raiz->esq = ArvoreDeBuscaInsere(raiz->esq,aluno);
        }else{
           raiz->dir = ArvoreDeBuscaInsere(raiz->dir, aluno);
        }

    }else{
        raiz = (tArv*) malloc(sizeof(tArv));
        raiz->esq = NULL;
        raiz->dir = NULL;
        raiz->aluno = aluno;
    }

    return raiz;
    
    
}

tArv* ArvoreDeBuscaRemove(tArv* raiz, tAluno* aluno){
    if(ehMaiorAluno(aluno,raiz->aluno)<0){
        raiz->esq = ArvoreDeBuscaRemove(raiz->esq,aluno);
    }else if(ehMaiorAluno(aluno , raiz->aluno)>0){
        raiz->dir = ArvoreDeBuscaRemove(raiz->dir,aluno);
    }else{
        // to no no que sera removido
        
        // 1 caso
        //o no é um folha
        if(raiz->esq == NULL && raiz->dir ==NULL){
            AlunoLibera(raiz->aluno);
            free(raiz);
            raiz = NULL;
        }
        // no com um filho na direita
        else if(raiz->esq == NULL){
            tArv* t = raiz;

            raiz = raiz->dir;
            
            AlunoLibera(t->aluno);
            free(t);
        }
        // no com um filho na esquerda
        else if(raiz->dir == NULL){
            tArv* t = raiz;

            raiz = raiz->esq;
          
            AlunoLibera(t->aluno);
            free(t);
        }
        // no com dois filhos
        else{
            tArv* f = raiz->esq;
            while(f->dir !=NULL){
                f = f->dir;
            }
            raiz->aluno = f->aluno;
            f->aluno = aluno;
            raiz->esq = ArvoreDeBuscaRemove(raiz->esq, aluno);
        }
    }
    return raiz;
}

tArv* ArvoreDeBuscaBusca(tArv* raiz, tAluno* aluno){
    if(raiz==NULL)
        return NULL;



    if(ehMaiorAluno(aluno,raiz->aluno) < 0){
        ArvoreDeBuscaBusca(raiz->esq,aluno);
    }else if(ehMaiorAluno(aluno,raiz->aluno) >0){
        ArvoreDeBuscaBusca(raiz->dir, aluno);
    }else return raiz;

}

void ArvoreDeBuscaLibera(tArv* raiz){
    if(raiz!= NULL){
        
        ArvoreDeBuscaLibera(raiz->esq);
        ArvoreDeBuscaLibera(raiz->dir);
        AlunoLibera(raiz->aluno);
        free(raiz);
    }

}


int ArvVazia (tArv* a){
    return a==NULL;
}




void ArvoreDeBuscaImprime(tArv* a, int nivel){
    if(!ArvVazia(a)){

        ArvoreDeBuscaImprime(a->esq,nivel+1);
        
        for(int i=0; i<nivel;i++) printf("  ");
        
        imprimeAluno(a->aluno);
        
        
        ArvoreDeBuscaImprime(a->dir,nivel+1);

    }
}

//retorna a quantidade de folhas da arvore
int ArvoreDeBuscaFolhas(tArv* raiz){
    if(ArvVazia(raiz)){
        return 0;
    }
    
    if(raiz->esq == NULL && raiz->dir == NULL){
        return 1;
    }
    

    return ArvoreDeBuscaFolhas(raiz->esq)+ ArvoreDeBuscaFolhas(raiz->dir);
}



int max(int a, int b){
    return (a>b)? a : b;
}

int ArvoreDeBuscaAltura(tArv* raiz){
    if(ArvVazia(raiz)){
        return -1;
    }
    return 1+  max(ArvoreDeBuscaAltura(raiz->esq), ArvoreDeBuscaAltura(raiz->dir));
}

int ArvoreDeBuscaContaNos(tArv* raiz){
    if(raiz == NULL)
        return 0;
    return 1+ ArvoreDeBuscaContaNos(raiz->esq) + ArvoreDeBuscaContaNos(raiz->dir); 
}

//pode usar while pra fazer essas duas funções
tArv* AcharMenorNo(tArv* raiz){
    if(raiz->esq == NULL)
        return raiz;
    AcharMenorNo(raiz->esq);
}
tArv* AcharMaiorNo(tArv* raiz){
    if(raiz->dir  == NULL)
        return raiz;
    AcharMaiorNo(raiz->dir);
}

tArv* RemoveNoSemLiberar(tArv* raiz, tAluno* aluno){
    if(ehMaiorAluno(aluno,raiz->aluno)<0){
        raiz->esq = RemoveNoSemLiberar(raiz->esq,aluno);
    }else if(ehMaiorAluno(aluno , raiz->aluno)>0){
        raiz->dir = RemoveNoSemLiberar(raiz->dir,aluno);
    }else{
        // to no no que sera removido
        
        // 1 caso
        //o no é um folha
        if(raiz->esq == NULL && raiz->dir ==NULL){

            raiz = NULL;
        }
        // no com um filho na direita
        else if(raiz->esq == NULL){
            tArv* t = raiz;

            raiz = raiz->dir;
            

        }
        // no com um filho na esquerda
        else if(raiz->dir == NULL){
            tArv* t = raiz;

            raiz = raiz->esq;

        }
        // no com dois filhos
        else{
            tArv* f = raiz->esq;
            while(f->dir !=NULL){
                f = f->dir;
            }
            raiz->aluno = f->aluno;
            f->aluno = aluno;
            raiz->esq = RemoveNoSemLiberar(raiz->esq, aluno);
        }
    }
    return raiz;
}

tArv* ArvoreDeBuscaBalancea(tArv* raiz){
    if(raiz == NULL)
        return NULL;

    int numSae = ArvoreDeBuscaContaNos(raiz->esq);
    int numSad = ArvoreDeBuscaContaNos(raiz->dir);

    if(numSae >= numSad+2){
        tArv* maiorNoSae= AcharMaiorNo(raiz->esq);
        maiorNoSae->esq = RemoveNoSemLiberar(raiz->esq, maiorNoSae->aluno);// so nao liberar o ponteiro pra usar ele depois
        maiorNoSae->dir= raiz;
        raiz->esq = NULL;
        return ArvoreDeBuscaBalancea(maiorNoSae);
    }else if( numSad >= numSae +2){
        tArv* menorNoSad=AcharMenorNo(raiz->dir);
        menorNoSad->dir = RemoveNoSemLiberar(raiz->dir, menorNoSad->aluno);
        menorNoSad->esq = raiz;
        raiz->dir = NULL;
        return ArvoreDeBuscaBalancea(menorNoSad);
    }else if((numSad - numSae <=1)){
        return raiz;
    }
}