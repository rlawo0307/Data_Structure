#pragma once

#include <stdio.h>

#define MAX_QUEUE_SIZE 100

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

void Enqueue(int* queue, int* front, int* rear, int val)
{
	if (IsFull(*front, *rear))
	{
		printf("Queue is full : %d\n", val);
		return;
	}
	*rear = (*rear + 1) % MAX_QUEUE_SIZE;
	queue[*rear] = val;
}

void Dequeue(int* queue, int* front, int* rear)
{
	if (IsEmpty(*front, *rear))
	{
		printf("Queue is Empty\n");
		return;
	}
	*front = (*front + 1) % MAX_QUEUE_SIZE;
	printf("Pop : %d\n", queue[*front]);
}

void Peek(int* queue, int front)
{
	printf("%d", queue[front + 1]);
}

void Size(int front, int rear)
{
	printf("size : ");
	if (rear < front)
		printf("%d\n", MAX_QUEUE_SIZE - front + rear);
	else
		printf("%d\n", rear - front);
}

void Display(int* queue, int front, int rear)
{
	if (rear < front)
		rear += MAX_QUEUE_SIZE;

	printf("(front) ");
	for (int i = front + 1; i <= rear; i++)
		printf("%d ", queue[i % MAX_QUEUE_SIZE]);
	printf("(rear)\n");
}
