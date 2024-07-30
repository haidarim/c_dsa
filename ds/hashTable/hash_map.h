#ifndef HASH_MAP_H
#define HASH_MAP_H
#include "Map.h"
typedef struct HashMap
{
    struct HashMap *head;
    Map *kvTable;
    unsigned int mapSize;
} hm_t;

hm_t *createHashMap();

Map *find_optional(hm_t *hm, unsigned int index);

unsigned int positive_hash(hm_t *hm, void *key);

void put(hm_t *hm, void *key, void *value);

void *getVal(hm_t *hm, void *key);

void remove_key(hm_t *hm, void *key);

double FoLoad(hm_t *hm);

void free_hm(hm_t *hm);

#endif