#pragma warning(disable:4996)

#include <stdio.h>

#define MAX_STACK_SIZE 5

bool IsEmpty(int);
bool IsFull(int);
void Push(int*, int*, int);
void Pop(int*, int*);
void PrintStack(int*, int);

int main()
{
	int stack[MAX_STACK_SIZE] = { 0, };
	int top = -1;
	int val = 1;

	while (!IsFull(top))
	{
		Push(stack, &top, val);
		PrintStack(stack, top);
		val++;
	}
	while (!IsEmpty(top))
	{
		Pop(stack, &top);
		PrintStack(stack, top);
	}
	return 0;
}

bool IsEmpty(int top)
{
	if (top == -1)
		return true;
	return false;
}

bool IsFull(int top)
{
	if (top >= MAX_STACK_SIZE - 1)
		return true;
	return false;
}

void Push(int* stack, int* top, int val)
{
	(*top)++;
	stack[*top] = val;
}

void Pop(int* stack, int* top)
{
	printf("Pop : %d\n", stack[*top]);
	(*top)--;
}

void PrintStack(int* stack, int top)
{
	printf("(bottom) ");
	for(int i=0; i<=top; i++)
		printf("%d ", stack[i]);
	printf("(top)\n");
}