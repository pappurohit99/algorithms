#ifndef LIST_H
#define LIST_H

typedef struct ListNode
{
    int data;
    struct ListNode *next;
} node;

node *createList();
// Main APIs

// Getters
int list_get(node *head, int pos);

// Modifiers
node *list_insert(node *head, int key, int pos);
node *list_insert_head(node *head, int key);
node *list_insert_tail(node *head, int key);
node *list_remove(node *head, int key);
node *list_removeAt(node *head, int pos);
node *list_replace(node *head, int key, int val);

// Query
int list_find(node *head, int key);
int list_size(node *head);
int list_isEmpty(node *head);
int list_isFull(node *head);

// util APIs
void printList(node *head);
node *prepList(int *arr, int n);
int *getArrayFromList(node *head);

#endif
