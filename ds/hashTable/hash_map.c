#include <stdlib.h>
#include <stdio.h>
#include "hash_map.h"
#include "Map.h"

#define MAX_LOAD_F 2.0
#define MULTIPLIER 1.5
#define MIN_LOAD_F

hm_t *createHashMap()
{
    hm_t *m = (hm_t *)malloc(sizeof(hm_t));
    m->kvTable = createMap();
    m->mapSize = 0;
    return m;
}

Map *find_optional(hm_t *hm, unsigned int index)
{
    return l_get(hm->kvTable, index);
}

void put(hm_t *hm, char *key, char *value)
{
    int i = positive_hash(hm, key); // get i of h(x)
    printf("inside put!<---------------\n\n");
    Map *map = (Map *)find_optional(hm, i);
    add_head(map, key, value);
    hm->mapSize++;
}

char *getVal(hm_t *hm, char *key)
{
    int i = positive_hash(hm, key);
    return find_optional(hm, i);
}

double FoLoad(hm_t *hm)
{
    return (double)hm->mapSize / hm->kvTable->listSize;
}

unsigned int hash_code(const char *key)
{
    unsigned int hash = 0;
    while (*key)
    {
        hash = (hash + 31) + *key++;
    }
    return hash;
}

unsigned int positive_hash(hm_t *hm, char *key)
{
    unsigned int hash = hash_code(key);
    return hash & 0x7fffffff % hm->kvTable->listSize;
}

void remove_key(hm_t *hm, char *key)
{
}

void free_hm(hm_t *hm)
{
    for (unsigned int i = 0; i < hm->mapSize; i++)
    {
        freeList(&hm->kvTable[i]);
    }
    free(hm->kvTable);
    free(hm);
}
