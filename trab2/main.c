#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* pegarExtensaoArquivo(const char* nomeDeArquivo) {
    const char* dot = strrchr(nomeDeArquivo, '.');
    if (!dot || dot == nomeDeArquivo) {
        return "";
    }
    return dot + 1;
}


int main(int argc, char*argv[]){

    if(argc !=2){
        printf("Erro ao fornecer os argumentos do programa\n");
        exit(-1);
    }

    const char* extensao = pegarExtensaoArquivo(argv[1]);
    if(!strcmp(extensao,"zip")){
        //descompactar o arquivo
    }else{
        //compactar o arquivo
    }




    return 0;
}