#ifndef STACK_HPP
#define STACK_HPP

typedef struct StackStructure {
	int *arr;
	int length;
	int capacity;
} stack;

// Constructor
stack* createStack(int);

// Access modifiers
stack* push(stack* s, const int el);
stack* pop(stack* s);

// Peek
int peek(stack* s);

// Query
int isFull(stack* s);
int isEmpty(stack *s);

// Destructor
void deleteStack(stack*);

// Utility APIS
void printStack(stack*, char);
#endif