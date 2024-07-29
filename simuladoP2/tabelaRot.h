#ifndef TABELA_ROT
#define TABELA_ROT

typedef struct pacote PACOTE;


PACOTE** TabelaHotInicia();
int TabelaRotFunc(char* destinarion);

void TabelaRotInsere(PACOTE** hash, char* destination, char* nextHop);

char* TabelaRotBusca(PACOTE** hash, char* destination);




#endif