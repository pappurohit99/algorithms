#include "list.h"
#include "../utils.h"
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

node *createList()
{
    return NULL;
}

#pragma region APIs
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

node *list_insert_head(node *head, int key)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = key;
    newNode->next = head;
    head = newNode;
    return head;
}

node *list_insert_tail(node *head, int key)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = key;
    newNode->next = NULL;
    if (!list_isEmpty(head))
    {
        node *ptr = head;
        while (ptr && ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    else
    {
        head = newNode;
    }
    return head;
}

node *list_insert(node *head, int key, int pos)
{
    // Zero indexed
    // Insert after pos - 1
    if (pos == 0)
    {
        return list_insert_head(head, key);
    }
    int size = list_size(head);
    if (pos == size)
    {
        return list_insert_tail(head, key);
    }
    else if (pos < size)
    {
        // find the ptr which is index - 1
        int ctr = -1;
        node *ptr = head;
        while (ptr && ptr->next)
        {
            ctr++;
            if (ctr == pos - 1)
            {
                break;
            }
        }
        node *temp = (node *)(malloc(sizeof(node)));
        temp->data = key;
        temp->next = ptr->next;
        ptr->next = temp;
        return head;
    }
    return head;
}

node *list_remove(node *head, int key)
{
    int pos = list_find(head, key);
    if (pos > -1)
    {
        return list_removeAt(head, pos);
    }
    return head;
}

node *list_removeAt(node *head, int pos)
{
    int size = list_size(head);
    if (pos >= 0 && pos < size)
    {
        if (pos == 0)
        {
            return head->next;
        }
        if (pos == size - 1)
        {
            node *ptr = head;
            while (ptr && ptr->next && ptr->next->next)
            {
                ptr = ptr->next;
            }
            ptr->next = NULL;
            return head;
        }
        node *ptr = head;
        int ctr = -1;
        while (ptr && ptr->next)
        {
            ctr++;
            if (ctr == pos - 1)
            {
                break;
            }
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
        return head;
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

int list_find(node *head, int key)
{
    node *ptr = head;
    int pos = -1;
    while (ptr)
    {
        pos++;
        if (ptr->data == key)
        {
            return pos;
        }
        ptr = ptr->next;
    }
    return -1;
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
#pragma endregion APIS

#pragma region utils

node *prepList(int *arr, int n)
{
    node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        head = list_insert_tail(head, arr[i]);
    }
    return head;
}

void printList(node *head)
{
    int *arr = getArrayFromList(head);
    int n = list_size(head);
    if (n > 0)
    {
        printArray(arr, n, ',');
    }
}

int *getArrayFromList(node *head)
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
        return arr;
    }
    return NULL;
}
#pragma endregion utils
