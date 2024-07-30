typedef struct Node
{
    void *e;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    int listSize;
} LinkedList;

void add_head(LinkedList *l, void *item);
LinkedList *createLinkedList();
void *l_get(LinkedList *l, int i);
void *set(LinkedList *l, int i, void *e);
void add(LinkedList *l, int i, void *e);
void *remove_element(LinkedList *l, int i);
int l_size(LinkedList *l);
void freeList(LinkedList *list);