#pragma warning(disable:4996)

#include <stdio.h>

#define MAX_QUEUE_SIZE 5

bool IsEmpty(int, int);
bool IsFull(int, int);
void AddQueue(int*, int*, int);
void DelQueue(int*, int*);
void PrintQueue(int*, int, int);

int main()
{
	int queue[MAX_QUEUE_SIZE] = { 0, };
	int front = -1;
	int rear = -1;
	int val = 1;

	while (!IsFull(front, rear))
	{
		AddQueue(queue, &rear, val);
		PrintQueue(queue, front, rear);
		val++;
	}
	while (!IsEmpty(front, rear))
	{
		DelQueue(queue, &front);
		PrintQueue(queue, front, rear);
	}
	return 0;
}

bool IsEmpty(int front, int rear)
{
	if (front == rear)
		return true;
	return false;
}

bool IsFull(int front, int rear)
{
	if (front == -1 && rear == MAX_QUEUE_SIZE - 1)
		return true;
	if(front == (rear+1)%MAX_QUEUE_SIZE)
		return true;
	return false;
}

void AddQueue(int* queue, int* rear, int val)
{
	*rear = (*rear + 1) % MAX_QUEUE_SIZE;
	queue[*rear] = val;
}

void DelQueue(int* queue, int* front)
{
	*front = (*front + 1) % MAX_QUEUE_SIZE;
	printf("Pop : %d\n", queue[*front]);
}

void PrintQueue(int* queue, int front, int rear)
{
	if (rear < front)
		rear += MAX_QUEUE_SIZE;

	printf("(front) ");
	for (int i = front+1; i <= rear; i++)
		printf("%d ", queue[i%MAX_QUEUE_SIZE]);
	printf("(rear)\n");
}