#include <stdlib.h>
#include <stdio.h>
#include "array_list.h"

LinkedList *createLinkedList()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->listSize = 0;
    return list;
}

void *l_get(LinkedList *list, int index)
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
    return current->e;
}

void *set(LinkedList *list, int index, void *item)
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
    void *old = current->e;
    current->e = item;
    return old;
}

void add_head(LinkedList *list, void *item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->e = item;
    // if (l->listSize == 0)
    //{
    newNode->next = list->head;
    list->head = newNode;
    //}

    list->listSize += 1;
}

void add(LinkedList *list, int index, void *item)
{
    if (index > list->listSize || index < 0)
    {
        printf("list index out of range");
        freeList(list);
        exit(-1);
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->e = item;
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

int l_size(LinkedList *list)
{
    return list->listSize;
}
void *remove_element(LinkedList *list, int index)
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
    void *removed_item = removed->e;
    free(removed);
    list->listSize -= 1;
    return removed_item;
}

void freeList(LinkedList *list)
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