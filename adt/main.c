#include "stack.h"
#include <stdio.h>

int main()
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
		printf("Stack Empty? :%d\n", isEmpty(s));
		printStack(s, ',');
	}
	return 0;
}