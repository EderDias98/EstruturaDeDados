#ifndef LISTAM_H
#define LISTAM_H
typedef struct NoM tNoM;
typedef struct listaM tListaM;

tListaM* criaListaVaziaM();


 
void insereFimListaM(tListaM* lista, char* item, char* desc); // correta
 
void liberaPrimeiroItemListaM(tListaM* lista); // correta

void liberaUltimoItemListaM(tListaM* lista); //correta
 
void liberaItemListaM(tListaM* lista, char* item); // correta

void liberaItemListaIdxM(tListaM* lista, int idx); // correto

void  imprimiListaM(tListaM* lista); // correto

void liberaNosDaListaM(tListaM* lista); //correto

void liberaListaM(tListaM* lista); //correto

char* getNomeM(tNoM* no);

int getTamM(tListaM* lista);

char* getAutorM(tNoM* no);

tNoM* getNoListaIdxM(tListaM* lista,int idx);
tNoM* getNoListaM(tListaM* lista, char* nome);

tNoM* copiaNoM(tNoM* no);

char* getDescM(tNoM* no);
#endif