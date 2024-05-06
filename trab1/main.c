#include "listaP.h"
#include "listaL.h"
#include "listaM.h"
#include <stdio.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "refatorar.h"
#include <string.h>

#define TAM_NOME 100



int main()
{

    FILE *amizade;
    
    // Abre o amizade em modo de leitura
    amizade = fopen("Entrada/amizade.txt", "r");

    // Verifica se o amizade foi aberto corretamente
    if (amizade == NULL)
    {
        printf("Erro ao abrir o amizade.\n");
        return 1;
    }

    tListaL* listaL = criaListaVaziaL();

    // Lê e exibe o conteúdo de amizade da primeira linha
    char amigo1[TAM_NOME] = {'\0'};
    char espaco = '\0';
    char* copia;
    // aqui e eu faço uma lista com os usuarios do spotfy
    while (fscanf(amizade, "%[^;\n]%c", amigo1, &espaco)){
        copia = copiaPalavra(amigo1);
        insereFimListaL(listaL,copia);
        if(espaco == '\n')
            break;
    }
    

    char amigo2[TAM_NOME] = {'\0'};

    tNoL* atual =NULL;

    char* copiaA = NULL;
    // crio uma struct de amigos para cada no do usuario(noL)
    while (fscanf(amizade, "%[^;\n]%*c%[^;\n]%*c", amigo1, amigo2) != EOF)
    {
        
        copia = copiaPalavra(amigo2);
        copiaA = copiaPalavra(amigo1);
        //procurar por amigo1 na listaL(dos usuarios) e depois acrecentar amigo2n na struct amigos;
        if(quemVemPrimeiro(listaL,copiaA,copia) == 1){
            atual = getNoListaL(listaL, amigo1);
            InsereAmigoListaL(atual, copia);
            free(copiaA);
        }else{
            atual = getNoListaL(listaL,amigo2);
            InsereAmigoListaL(atual, copiaA);
            free(copia);
        }
        
        
        
        memset(amigo1, '\0', sizeof(amigo1));
        memset(amigo2, '\0', sizeof(amigo2));
    }
    // até a aqui eu tenho uma listaL com os usuários e seus amigos na struct amigos
    // Fecha o amizade
 

    fclose(amizade);

    
    // ler a lista das playlists

    FILE *playlists;
    
    // Abre a playlist em modo de leitura
    playlists = fopen("Entrada/playlists.txt", "r");

    // Verifica se a playtlist foi aberto corretamente
    if (playlists == NULL)
    {
        printf("Erro ao abrir o playlists.\n");
        return 1;
    }
    int numP=0;

    char nomePlay[TAM_NOME];
    tLista* listaP;
    memset(amigo1, '\0', sizeof(amigo1));
    char* descMP;
    // crio lista de playlist e coloco ela em noL
    while (fscanf(playlists,"%[^;]%*c%d%*c", amigo1, &numP)!=EOF)
    {
        atual = getNoListaL(listaL, amigo1);
        listaP  =  criaListaVaziaP();
        for(int i=0; i<numP;i++){
            memset(nomePlay,'\0', sizeof(nomePlay));
            fscanf(playlists,"%[^;\n]%*c",nomePlay);
            copia = copiaPalavra(nomePlay);
            insereFimListaP(listaP,copia);
        }
        memset(amigo1, '\0', sizeof(amigo1));
       
        setListaPEmL(atual,listaP);

    }

    fclose(playlists);

 
    // agora eu tenho que carregar cada playlista com uma lista de musicas
    char nomeM[TAM_NOME];
    char descM[TAM_NOME];
    tListaM* listaM;
    tNo* noP;
    char caminhoPlay[TAM_NOME];
    char restM[TAM_NOME];
    char nDescM[TAM_NOME];
    char* nome_play;
    //carrego as musicas nas playlist
    for(int i=0; i<getTamL(listaL);i++){
        listaP = getListaPDeL(getNoListaIdxL(listaL,i));
        for(int j=0; j<getTamP(listaP);j++){
            noP =getNoListaIdxP(listaP,j);
            nome_play = getNomeP(noP);
            FILE* playlist;
            memset(caminhoPlay, '\0', sizeof(caminhoPlay));
            sprintf(caminhoPlay,"Entrada/%s",nome_play);
            // Abre a playlist em modo de leitura
            playlist = fopen(caminhoPlay, "r");

        // Verifica se a playlist foi aberto corretamente
            if (playlist == NULL)
            {
            printf("Erro ao abrir o %s\n", getNomeP(noP));
            return 1;
            }
            // ler essa playlist e criar a lista de musicas
            listaM = criaListaVaziaM();
            while(fscanf(playlist,"%[^-]%[^\n]%*c",nomeM, descM)!= EOF){
                //
                if(nomeM[strlen(nomeM)-1] != ' '){
                    strcat(nomeM,"-");
                    sscanf(descM,"%*c%[^-]%[^\n]%*c", restM, nDescM);
                    strcat(nomeM,restM);
                    descMP = copiaPalavra(nDescM);
                }else{
                    descMP = copiaPalavra(descM);
                }
                copia =copiaPalavra(nomeM);
                
                insereFimListaM(listaM,copia,descMP);
            }
            setListaMEmP(noP,listaM);
            fclose(playlist);
        }
         
    }

    




    //refatora a lista de acordo com a professora pediu
    refatoraListaL(listaL);
    // imprimiListaL(listaL);

    criaPastasEArquivos(listaL);
    
    //cria arquivo simillaridades
    criaSimilaridades(listaL);

    // libero a memoria alicada da listaL
    liberaListaL(listaL);
    return 0;
}