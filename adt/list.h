#ifndef LIST_H
#define LIST_H

typedef struct ListNode
{
    int data;
    struct ListNode *next;
} node;

node *createList();
// Main APIs
int list_get(node *head, int pos);
node *list_insert(node *head, int key, int pos);
node *list_remove(node *head, int key);
node *list_removeAt(node *head, int pos);
node *list_replace(node *head, int key, int val);
int list_size(node *head);
int list_isEmpty(node *head);
int list_isFull(node *head);

// util API
void printList(node *head);

#endif