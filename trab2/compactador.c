#include "compactador.h"
#include "arvore.h"

// Estrutura para a tabela de códigos Huffman
typedef struct {
    int caractere;
    char codigo[9];  // Assume-se que o código binário não excede 9 bits
}tTab;

void preencheTabela(tArv *raiz, tTab *tabela, char *codigoAtual, int prof) {
    if (raiz->esq) {
        // Descendo para o filho esquerdo (0)
        codigoAtual[prof] = '0';
        preencheTabela(raiz->esq, tabela, codigoAtual, prof + 1);
    }

    if (raiz->dir) {
        // Descendo para o filho direito (1)
        codigoAtual[prof] = '1';
        preencheTabela(raiz->dir, tabela, codigoAtual, prof + 1);
    }

    if (!(raiz->esq) && !(raiz->dir)) {
        // Chegou a uma folha, registra o caractere e seu código binário na tabela
        tabela[raiz->ch].caractere = raiz->ch;
        codigoAtual[prof] = '\0';  // Finaliza a string de código binário
        strcpy(tabela[raiz->ch].codigo, codigoAtual);
    }
}


int comparaPesos(const void *a, const void *b) {
    
    
    if(a == NULL || b == NULL)
        return 1;
    
    const tArv *folha_a = (const tArv *)a;
    const tArv *folha_b = (const tArv *)b;


    return getPeso(a) - getPeso(b);
}
int ehBit1(char c, int bitPosition) {
    return (c & (1 << bitPosition)) != 0;
}
void salvarCaracterNoBitMap(bitmap*bm,char c){
    for(int i=7, i>=0;i--){
        if(ehBit1(c,i)){
            bitmapAppendLeastSignificantBit(bm,1);
        }else{
            bitmapAppendLeastSignificantBit(bm,0);
        }
    }
}
void salvarCodigoNoBitMap(bitmap* bm ,char* cod){
    for(int i=0; cod[i]!='\0';i++){
        if(cod[i]=='1'){
            bitmapAppendLeastSignificantBit(bm,1);
        }else{
            bitmapAppendLeastSignificantBit(bm,0);
        }
    }
}



void ArvSalvaPreOrdem(tArv* a, bitmap* bm) {
    if (a != NULL) {
        // Armazena o nó atual
        if(getCaractere(a) ==-1){
            bitmapAppendLeastSignificantBit(bm,0);
        }else if(getCaractere(a) == 257){
            bitmapAppendLeastSignificantBit(bm,1);
        }
        else{
            bitmapAppendLeastSignificantBit(bm,1);
            salvarCaracterNoBitMap(bm,getCaractere(a));
        }
        
        // Recursivamente armazena os filhos
        ArvSalvaPreOrdem(a->esq, bm);
        ArvSalvaPreOrdem(a->dir, bm);
    }
}

void salvaTexto(bitmap* bm, FILE* f, tTab* tb){
    fseek(f, 0, SEEK_SET);

    int ch; // Variável para armazenar o ch lido
    while ((ch = fgetc(f)) != EOF) {
        salvarCodigoNoBitMap(tb[ch].codigo);
    }
    salvarCodigoNoBitMap(tb[128].codigo);
    // salvar um novo cod pra simbolizar o fim que sera 128

}

void excluiArquivo(char* arquivo){
    if (remove(caminho) == 0) {
        printf("Arquivo deletado com sucesso.\n");
    } else {
        printf("Erro ao deletar o arquivo");
        exit(-1);
    }
}

void compactaArquivo(char *caminho){
    // contar a frequencia de caracteres do arquivo dado

    FILE* f = fopen(caminho,"r");
    int frq_char[256] = {0};

    int ch; // Variável para armazenar o ch lido

    // Loop para ler e imprimir cada ch do arquivo
    int qtd_bytes =0;
    while ((ch = fgetc(f)) != EOF) {
        frq_char[ch]++;
        qtd_bytes++;
    }
    // fazer a arvore binaria de compactacao
    // preciso de uma lista de arvores;
    tArv* lista[256];

    // inicializando a lista as arvores pra o algoritmo de huffman
    for (int i = 0; i < 256; i++) {
        lista[i] = ArvCria(frq_char[i], i, NULL, NULL);  
    }
    // preciso  ordenar na lista em ordem crescente usando os pesos
    // função pra ordenar sempre a lista, vou usar qsorte
    qsort(lista,256,sizeof(tArv*), comparaPesos);
    int qtd_arv=256;
    while ( qtd_arv>1)
    {
        
        tArv* t1 = lista[0];
        tArv* t2 = lista[1];
        tArv* t3 = combinaArvores(t1,t2);
        lista[0] = t3;
        lista[1] = NULL;
        qsort(lista,256,sizeof(tArv*), comparaPesos);
        qtd_arv--;
    }
    tArv* arv = lista[0];// a ultima arqvore sera a primeira da lista e o resto sera preenchido com NULL

    // fazer a tabela eu preciso de tabela? preciso pra meu algoritmo andar mais rápido se nao vai demorar muito
    tTab tab[256];
    char codigoAtual[9]={'\0'};
    preencheTabela(arv,&tab,&codigoAtual,0);

    //criar um arquivo novo pra escrever as mudancas
    char novoCaminho[300]={'\0'};
    strcat(novoCaminho,caminho);
    strcat(novoCaminho,".zip");
    FILE* nf= fopen(novoCaminho,"w+");
    bitmap* bitmap = bitmapInit(8*qtd_bytes + 256*(8));
    //envolve trabalhar com bits
    // tenho que salvar a arvore
    ArvSalvaPreOrdem(arv,bitmap);
    //salvar o texto
    salvaTexto(bitmap,f,tab);
    //salvar do bitmap pra nf
    fwrite(bitmapGetContents(bitmap),sizeof(char),bitmapGetLength(bitmap),nf);

    fclose(f);
    excluiArquivo(caminho);
    fclose(nf);  
}



tArv* ArvCarregaPreOrdem(bitmap* bm, int index) {
    char bit = bitmapGetBit(bm,index);

    if (bit == '1') {
        int caractere = fgetc(file);
        tArv* a = ArvCria(0,caractere,NULL,NULL);
        return a; // Folha não tem filhos
    } else {
        tArv* a = ArvCria(0,-1,ArvCarregaPreOrdem(bm,index+9), ArvCarregaPreOrdem(bm,index+9)) // -1 para nós internos
        return a;
    }
}
void descompactaArquivo(char * caminho){
    // ler a Arvore 
}




