#include <stdlib.h>
#include <limits.h>
#include <assert.h>

#include "stack.h"
#include "../utils.h"

// Constructor
stack *createStack(const int N)
{
	assert(N > 0);
	stack *s;
	s = (stack *)malloc(sizeof(stack));
	s->arr = (int *)malloc(N * sizeof(int));
	s->length = 0;
	s->capacity = N;
	return s;
}

// Main APIs
stack *push(stack *pStack, const int el)
{
	if (!isFull(pStack))
	{
		pStack->arr[pStack->length] = el;
		pStack->length++;
	}
	return pStack;
}

stack *pop(stack *pStack)
{
	if (!isEmpty(pStack))
	{
		pStack->length--;
	}
	return pStack;
}

int peek(stack *pStack)
{
	if (!isEmpty(pStack))
	{
		return pStack->arr[pStack->length - 1];
	}
	return INT_MIN;
}

int isFull(stack *pStack)
{
	return pStack->length == pStack->capacity;
}

int isEmpty(stack *pStack)
{
	return pStack->length == 0;
}

// Utility APIs
void printStack(stack *pStack, char separator)
{
	printArray(pStack->arr, pStack->length, separator);
}