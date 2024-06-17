#ifndef COMPACTADOR_H
#define COMPACTADOR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitmap.h"

/**
 * @brief compactar o arquivo, vou fechar o arquivo dado 
 * e acriar um novo compactador com um novo nome
 * @param f ponteiro para o arquivo a ser compactado
*/
void compactaArquivo(FILE* f);



#endif