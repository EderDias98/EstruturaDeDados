#ifndef CACHORRO_H
#define CACHORRO_H



typedef struct cachorro Cachorro;

Cachorro* inicCachorro(char* nome, int estado);

void imprimeCachorro(Cachorro* c);


void liberaCachorro(Cachorro* c);

int ehCaoBravo(Cachorro* c);
void atribuiNivelAgressividadeCachorro(Cachorro* c, int estado);


char* getNome(Cachorro* c);
#endif
