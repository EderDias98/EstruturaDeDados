#ifndef ITEM_H
#define ITEM_H

typedef struct item ITEM;
int ItemCompara(void* item_1v,void* item2_v);
void ItemImprime(void* item_v);
ITEM* ItemInicia(int num);
void ItemLibera(void* item_v);
#endif