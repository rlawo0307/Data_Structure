#pragma warning(disable:4996)

#include <stdio.h>

#define MAX_QUEUE_SIZE 8

bool IsEmpty(int, int);
bool IsFull(int, int);
void AddFront(int*, int*, int*, int);
void AddRear(int*, int*, int*, int);
void DelFront(int*, int*, int*);
void DelRear(int*, int*, int*);
void GetFront(int*, int);
void GetRear(int*, int);
void Display(int*, int, int);

int main()
{
	int dq[MAX_QUEUE_SIZE] = { 0, }; 
	int front = 0; 
	int rear = 0; 

	AddFront(dq, &front, &rear, 1);
	AddFront(dq, &front, &rear, 2);
	AddRear(dq, &front, &rear, 3);
	Display(dq, front, rear);

	AddRear(dq, &front, &rear, 4);
	AddRear(dq, &front, &rear, 5);
	AddFront(dq, &front, &rear, 6);
	AddRear(dq, &front, &rear, 7);
	AddRear(dq, &front, &rear, 8); // Fail
	Display(dq, front, rear);

	DelFront(dq, &front, &rear);
	Display(dq, front, rear);
	DelRear(dq, &front, &rear);
	Display(dq, front, rear);

	AddFront(dq, &front, &rear, 8);
	AddRear(dq, &front, &rear, 9);
	AddRear(dq, &front, &rear, 10); // Fail
	AddFront(dq, &front, &rear, 10); // Fail
	Display(dq, front, rear);

	GetFront(dq, front);
	GetRear(dq, rear);
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
	dq[*front] = val;
	*front = (*front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; // 음수처리
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
	if (IsEmpty(*front, *rear))
	{
		printf("Queue is Empty\n");
		return;
	}
	*front = (*front + 1) % MAX_QUEUE_SIZE;
	printf("Pop : %d\n", dq[*front]);
}

void DelRear(int* dq, int* front, int* rear)
{
	if (IsEmpty(*front, *rear))
	{
		printf("Queue is Empty\n");
		return;
	}
	printf("Pop : %d\n", dq[*rear]);
	*rear = (*rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void GetFront(int* dq, int front)
{
	printf("front : %d\n", dq[front + 1]);
}

void GetRear(int* dq, int rear)
{
	printf("rear : %d\n", dq[rear]);
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
