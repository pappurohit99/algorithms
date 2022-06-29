#include "stack.h"
#include "list.h"
#include <stdio.h>

void testStack();
void testList();

int main()
{
	testList();
	return 0;
}

void testStack()
{
	stack *s = createStack(5);

	for (int i = 1; i <= 5; i++)
	{
		s = push(s, i * i);
	}

	printStack(s, ',');
	for (int i = 6; i >= 1; i--)
	{
		printf("Top element: %d\n", peek(s));
		s = pop(s);
		printf("Stack Empty? :%d\n", stack_isEmpty(s));
		printStack(s, ',');
	}
}

void testList()
{
	node *listNode = createList();
	for (int i = 1; i <= 5; i++)
	{
		listNode = list_insert(listNode, i * i, list_size(listNode));
	}
	printList(listNode);
}