#ifndef CACHORRO_H
#define CACHORRO_H

typedef struct cachorro Cachorro;



Cachorro* inicCachorro(char* nome, int estado);

void imprimeCachorro(Cachorro* c);


void liberaCachorro(Cachorro* c);


char* getNomeCachorro(Cachorro * c);


int getEstadoCachorro(Cachorro* c);

void atribuiNivelAgressividadeCachorro(Cachorro* c, int estado);


#endif