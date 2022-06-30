#include "list.h"
#include "../utils.h"
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

node *createList()
{
    return NULL;
}

int list_get(node *head, int pos)
{
    int ctr = -1;
    while (head)
    {
        ctr += 1;
        if (ctr == pos)
        {
            return head->data;
        }
        head = head->next;
    }
    return INT_MIN;
}

node *list_insert(node *head, int key, int pos)
{
    // Zero indexed
    // Insert after pos - 1
    int ctr = -1;
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = key;
    newNode->next = NULL;
    if (head == NULL)
    {
        return newNode;
    }
    if (pos == 0)
    {
        newNode->next = head;
        return newNode;
    }
    node *ptr = head;
    while (ptr->next)
    {
        ctr = ctr + 1;
        if (ctr == pos - 1)
        {
            newNode->next = ptr->next;
            ptr->next = newNode;
            return head;
        }
    }
    ptr->next = newNode;
    return head;
}

node *list_remove(node *head, int key)
{
    node *ptr = head;
    assert(head != NULL);
    if (head->data == key)
    {
        return head->next;
    }
    while (ptr->next)
    {
        if (ptr->next->data == key)
        {
            ptr->next = ptr->next->next;
            break;
        }
    }
    return head;
}

node *list_removeAt(node *head, int pos)
{
    node *ptr = head;
    assert(head != NULL);
    if (pos == 0)
    {
        return head->next;
    }
    int ctr = 0;
    while (ptr->next)
    {
        if (ctr == pos)
        {
            ptr->next = ptr->next->data;
            break;
        }
        ctr++;
    }
    return head;
}

node *list_replace(node *head, int key, int value)
{
    node *ptr = head;
    while (ptr)
    {
        if (ptr->data == key)
        {
            ptr->data = value;
            return head;
        }
        ptr = ptr->next;
    }
    return head;
}

int list_size(node *head)
{
    int ctr = 0;
    while (head)
    {
        head = head->next;
        ctr++;
    }
    return ctr;
}

int list_isEmpty(node *head)
{
    return head == NULL;
}

int list_isFull(node *head)
{
    node *tNode = (node *)malloc(sizeof(node));
    return tNode == NULL;
}

// Utility APIs
void printList(node *head)
{
    const int N = list_size(head);
    if (N > 0)
    {
        int *arr = (int *)malloc(N * sizeof(int));
        int i = 0;
        while (head)
        {
            arr[i++] = head->data;
            head = head->next;
        }
        printArray(arr, N, ',');
    }
}