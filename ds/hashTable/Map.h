#ifndef MAP_H
#define MAP_H

typedef struct Node
{
    char *key;
    char *value;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    int listSize;
} Map;

void add_head(Map *map, char *key, char *value);
Map *createMap();
char *l_get(Map *map, int i);
char *set(Map *map, int i, char *key, char *value);
void add(Map *map, int i, char *key, char *value);
char *remove_element(Map *map, int i);
int l_size(Map *map);
void freeList(Map *mapist);

#endif