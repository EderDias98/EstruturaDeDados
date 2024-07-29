#include "item.h"
#include <stdio.h>
#include <stdlib.h>


struct item{
    int num;
};

int ItemCompara(void* item1_v, void* item2_v){
    ITEM* item1 = (ITEM*) item1_v;
    ITEM* item2 = (ITEM*) item2_v;

    if(item1->num == item2->num){
        return 0;
    }else if(item1->num < item2->num){
        return -1;
    }else if(item1->num > item2->num){
        return 1;
    }

}
void ItemImprime(void* item_v){
    ITEM* item = (ITEM*) item_v;
    if(item)
        printf("%d\n", item->num);
    else  printf("Item nao encontrado\n");
}
ITEM* ItemInicia(int num){
    ITEM* item =(ITEM*) malloc(sizeof(ITEM));
    item->num = num;
    return item;
}
void ItemLibera(void* item_v){
    ITEM* item = (ITEM*) item_v;
    free(item);
}