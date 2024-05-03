#include "refatorar.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "listaL.h"
#include "listaM.h"
#include "listaP.h"
#include <unistd.h>
#include <sys/stat.h>

char *copiaPalavra(const char *palavra) {
    // Obter o tamanho da palavra
    size_t tamanho = strlen(palavra);

    // Alocar memória para a cópia da palavra (incluindo o caractere nulo de terminação)
    char *copia = (char *)malloc((tamanho + 1) * sizeof(char));

    // Verificar se a alocação de memória foi bem-sucedida
    if (copia == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória\n");
        exit(EXIT_FAILURE);
    }

    // Copiar a palavra para a memória alocada
    strcpy(copia, palavra);

    // Adicionar o caractere nulo de terminação
    copia[tamanho] = '\0';

    return copia;
}

struct autores{
    char** vet;
    int tam;
};

tAutores* criaAutores(){
    tAutores* autores = (tAutores*) malloc(sizeof(tAutores));
    autores->tam =0;
    autores->vet = (char**) malloc(sizeof(char*));
    return autores;
}

tAutores* preencheAutores(tLista* listaP){

    tNo* noP;
    tListaM* listaM;
    tNoM* noM;
    tAutores* autores = criaAutores();
    char* nome;

    for(int j=0; j<getTamP(listaP);j++){
        noP =getNoListaIdxP(listaP,j);
        listaM = getListaMDeP(noP);
        for(int k=0; k< getTamM(listaM);k++){

            noM = getNoListaIdxM(listaM,k);
            nome = getAutorM(noM);
            nome = copiaPalavra(nome);
            if(ehNomeUnico(autores, nome)){
                insereAutores(autores,nome);
            }
        }
    }
    
    return autores;
}

void insereAutores(tAutores* autores, char*nome){
    autores->tam++;
    autores->vet =(char**) realloc(autores->vet, autores->tam* sizeof(char*));
    autores->vet[autores->tam-1] = nome;
}
void liberaAutores(tAutores* autores){
    for(int i=0; i<autores->tam;i++){
        free(autores->vet[i]);
    }
    free(autores->vet);
    free(autores);
}

void imprimiAutores(tAutores* autores){
    for(int i=0; i<autores->tam;i++){
        printf("%s ", autores->vet[i]);
    }
    printf("\n");
}

int ehNomeUnico(tAutores* autores, char* nome){
    for(int i=0; i<autores->tam;i++){
        if(strcmp(autores->vet[i], nome) == 0)
            return 0;
    }
    return 1;
}

char* getNomeAutor(tAutores* autores, int idx){
    return autores->vet[idx];
}


tLista* criaPlaylistFatorada(tAutores* autores, tLista* ListaP){

    // colocar no nome certo das playlists
    char *novoNome;

    // nova playlist como todas as musicas dos autores
    tLista* nListaP;
    tNo* noP;
    tListaM* listaMN;
    tListaM* listaMA;
    tNoM* noM;
    char* autor;
    char* nome;
    nListaP = criaListaVaziaP();
 
    for(int i=0; i< autores->tam;i++){
        novoNome = copiaPalavra(autores->vet[i]);
        //tirar o espaco do final dos nomes do autores
        novoNome[strlen(novoNome)-1] ='\0';
        strcat(novoNome,".txt");
        
        insereFimListaP(nListaP,novoNome);


        nome = autores->vet[i];
        listaMN = criaListaVaziaM();
        for(int j=0; j<getTamP(ListaP);j++){
            

            noP =getNoListaIdxP(ListaP,j);
            listaMA = getListaMDeP(noP);

            for(int k=0; k< getTamM(listaMA);k++){

                noM =getNoListaIdxM(listaMA,k);
                autor = copiaPalavra(getAutorM(noM));  
                //testar se musica e do mesmo autor e se for colocar na listaM
                if(strcmp(autor,nome)==0){
                    //colocar musica na nova lista de musica
                    insereFimListaM(listaMN, autor, copiaPalavra(getDescM(noM)));
                }
            }
            
        }
        //colocar a nova lista de musica no no da lista de playlist 
        setListaMEmP(getNoListaIdxP(nListaP,i), listaMN);
    }


    return nListaP;
}

void refatoraListaL(tListaL* listaL){
    
    tLista* listaPA;
    tLista* listaPN;
    tNoL* noL;
    for(int i=0; i< getTamL(listaL);i++){
        noL = getNoListaIdxL(listaL,i);
        listaPA = getListaPDeL(noL);

        tAutores* autores = preencheAutores(listaPA);
        imprimiAutores(autores);

        listaPN = criaPlaylistFatorada(autores,listaPA);

        // imprimiListaP(listaPN);

        
        setListaPEmL(noL,listaPN);
 
    }
}

void criaPastasEArquivos(tListaL* listaL){
    char nome_da_pasta[100];
    // Cria a pasta com permissões padrão
    sprintf(nome_da_pasta,"SaidaM");
    if (mkdir(nome_da_pasta, 0777) == 0) {
        printf("Pasta \"%s\" criada com sucesso.\n", nome_da_pasta);
    } else {
        fprintf(stderr, "Erro: Falha ao criar a pasta \"%s\".\n", nome_da_pasta);
    }
    tNoL* noL;
    tNo* noP;
    tLista* listaP;
    char nome_arquivo[200];
    tListaM* listaM;
    tNoM* noM;

    sprintf(nome_arquivo,"SaidaM/played-refatorada.txt");
    FILE *arquivoF = fopen(nome_arquivo, "w");
    if (arquivoF == NULL) {
        fprintf(stderr, "Erro: Falha ao criar o arquivo \"%s\".\n", nome_arquivo);
        
    }

    for(int i=0; i< getTamL(listaL);i++){
        noL = getNoListaIdxL(listaL,i);
        
        sprintf(nome_da_pasta,"SaidaM/%s", getNomeL(noL));

        if (mkdir(nome_da_pasta, 0777) == 0) {
            printf("Pasta \"%s\" criada com sucesso.\n", nome_da_pasta);
        } else {
            fprintf(stderr, "Erro: Falha ao criar a pasta \"%s\".\n", nome_da_pasta);
        }

        //colocar as playlist na pasta com nome;
        listaP = getListaPDeL(noL);

        fprintf(arquivoF,"%s;%d;", getNomeL(noL), getTamP(listaP));
        for(int j=0; j<getTamP(listaP);j++){
            noP =getNoListaIdxP(listaP,j);
            
            if(j !=getTamP(listaP) -1){
                fprintf(arquivoF,"%s;", getNomeP(noP));
            }else{
                fprintf(arquivoF,"%s\n", getNomeP(noP));
            }
            
            // Nome do arquivo que você deseja criar
            memset(nome_arquivo,'\0', sizeof(nome_arquivo));
            sprintf(nome_arquivo,"%s/%s", nome_da_pasta, getNomeP(noP));
             // Abrir o arquivo no modo de escrita ("w")
            FILE *arquivo = fopen(nome_arquivo, "w");

            // Verificar se o arquivo foi aberto corretamente
            if (arquivo == NULL) {
                fprintf(stderr, "Erro: Falha ao criar o arquivo \"%s\".\n", nome_arquivo);
                
            }

            //imprimirMusicasNoArquivo
            listaM = getListaMDeP(noP);
            for(int k=0; k< getTamM(listaM);k++){
                noM = getNoListaIdxM(listaM,k);
                fprintf(arquivo,"%s%s\n", getAutorM(noM), getDescM(noM));
            }
            // Fechar o arquivo
            fclose(arquivo);

        }
    }
    fclose(arquivoF);
}
