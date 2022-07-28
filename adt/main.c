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
	int arr[] = {1, 2, 3, 4, 5};
	int size = sizeof(arr) / sizeof(arr[0]);
	node *head = prepList(arr, size);
	printList(head);
}