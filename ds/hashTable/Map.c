#include <stdlib.h>
#include <stdio.h>
#include "Map.h"

Map *createMap()
{
    Map *list = (Map *)malloc(sizeof(Map));
    list->head = NULL;
    list->listSize = 0;
    return list;
}

void *l_get(Map *list, int index)
{
    if (index > list->listSize || index < 0)
    {
        printf("list index out of range");
        freeList(list);
        exit(-1);
    }
    Node *current = list->head;
    for (int j = 0; j < index; j++)
    {
        current = current->next;
    }
    return current->value;
}

void *set(Map *list, int index, void *key, void *value)
{
    if (index > list->listSize || index < 0)
    {
        printf("list index out of range");
        freeList(list);
        exit(-1);
    }
    Node *current = list->head;
    for (int j = 0; j < index; j++)
    {
        current = current->next;
    }
    void *old = current->key;
    current->key = key;
    current->value = value;
    return old;
}

void add_head(Map *map, void *key, void *value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    // if (l->listSize == 0)
    //{
    newNode->next = map->head;
    map->head = newNode;
    //}

    map->listSize += 1;
}

void add(Map *list, int index, void *key, void *value)
{
    if (index > list->listSize || index < 0)
    {
        printf("list index out of range");
        freeList(list);
        exit(-1);
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    if (index == 0)
    {
        newNode->next = list->head;
        list->head = newNode;
    }
    else
    {
        Node *prev = list->head;
        for (int j = 0; j < index - 1; j++)
        {
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }
    list->listSize += 1;
}

int l_size(Map *list)
{
    return list->listSize;
}
void *remove_element(Map *list, int index)
{
    if (index > list->listSize || index < 0)
    {
        printf("list index out of range");
        freeList(list);
        exit(-1);
    }
    Node *removed;
    if (index == 0)
    {
        removed = list->head;
        list->head = removed->next;
    }
    else
    {
        Node *prev = list->head;
        for (int j = 0; j < index - 1; j++)
        {
            prev = prev->next;
        }
        removed = prev->next;
        prev->next = removed->next;
    }
    void *removed_item = removed->key;
    free(removed);
    list->listSize -= 1;
    return removed_item;
}

void freeList(Map *list)
{
    while (list->head != NULL)
    {
        printf("rmoved item is: %s\n", (char *)remove_element(list, 0));
    }
    if (l_size(list) != 0)
    {
        perror("failde to remove all!");
        exit(-1);
    }
    free(list);
}

// int main(void)
// {
//     Map *map = createMap();
//     add_head(map, "fjant", "khar");
//     add_head(map, "chaqq", "badboy");
//     add_head(map, "chaq", "khar");
//     add_head(map, "gooze", "badboy");
//     add_head(map, "chaqis", "...");
//     add_head(map, "gooh", "sag");

//     for (int i = 0; i < 6; i++)
//     {
//         printf("the value of index: %d is: %s\n", i, (char *)l_get(map, i));
//     }

//     add(map, 6, "muchis", "muchollo");
//     printf("the value of index: %d is: %s\n", 6, (char *)l_get(map, 6));
//     freeList(map);
//     return 0;
// }