#pragma warning(disable:4996)

#include <stdio.h>

#define MAX_QUEUE_SIZE 8

bool IsEmpty(int, int);
bool IsFull(int, int);
void AddFront(int*, int*, int*, int);
void AddRear(int*, int*, int*, int);
void DelFront(int*, int*, int*);
void DelRear(int*, int*, int*);
void GetFront(int*, int*, int*);
void GetRear(int*, int*, int*);
void Display(int*, int, int);

int main()
{
	int dq[MAX_QUEUE_SIZE] = { 0, }; 
	int front = 0; 
	int rear = 0; 

	AddRear(dq, &front, &rear, 1);
	AddRear(dq, &front, &rear, 2);
	AddRear(dq, &front, &rear, 3);
	printf("%d %d\n", front, rear);
	AddFront(dq, &front, &rear, 4);
	Display(dq, front, rear);
	printf("%d %d\n", front, rear);
}

bool IsEmpty(int front, int rear)
{
	if (front == rear)
		return true;
	return false;
}

bool IsFull(int front, int rear)
{
	if (front == (rear + 1) % MAX_QUEUE_SIZE)
		return true;
	return false;
}

void AddFront(int* dq, int* front, int* rear, int val)
{
	if (IsFull(*front, *rear))
	{
		printf("Queue is Full : %d\n", val);
		return;
	}
	*front = (*front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; // 음수처리
	printf("%d\n", *front);
	dq[*front] = val;
}

void AddRear(int* dq, int* front, int* rear, int val)
{
	if (IsFull(*front, *rear))
	{
		printf("Queue is Full : %d\n", val);
		return;
	}
	*rear = (*rear + 1)% MAX_QUEUE_SIZE;
	dq[*rear] = val;
}

void DelFront(int* dq, int* front, int* rear)
{

}

void DelRear(int* dq, int* front, int* rear)
{

}

void GetFront(int* dq, int* front, int* rear)
{

}

void GetRear(int* dq, int* front, int* rear)
{

}

void Display(int* dq, int front, int rear)
{
	if (rear < front)
		rear += MAX_QUEUE_SIZE;

	printf("(front) ");
	for (int i = front + 1; i <= rear; i++)
		printf("%d ", dq[i % MAX_QUEUE_SIZE]);
	printf("(rear)\n");
}
