#pragma once
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef struct QUEUE
{
	int* q;
	int front;
	int rear;
}Queue;

void InitQueue(Queue* q)
{
	q->q = (int*)calloc(sizeof(int), MAX_QUEUE_SIZE);
	if (q->q == NULL)
	{
		printf("Calloc Fail\n");
		return;
	}
	memset(q->q, 0, MAX_QUEUE_SIZE);
	q->front = 0;
	q->rear = 0;
}

bool IsEmpty(Queue* q) // int front, int rear)
{
	if (q->front == q->rear)
		return true;
	return false;
}

bool IsFull(Queue* q) // int front, int rear)
{
	if (q->front == (q->rear + 1) % MAX_QUEUE_SIZE)
		return true;
	return false;
}

void Enqueue(Queue* q, int val) // int* queue, int* front, int* rear, int val)
{
	if (IsFull(q))
	{
		printf("Queue is full : %d\n", val);
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->q[q->rear] = val;
}

int Dequeue(Queue* q) // int* queue, int* front, int* rear)
{
	if (IsEmpty(q))
	{
		//printf("Queue is Empty\n");
		return -1;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->q[q->front];
}

int Peek(Queue* q) // int* queue, int front)
{
	return q->q[q->front + 1];
}

void Size(Queue* q) // int front, int rear)
{
	printf("size : ");
	if (q->rear < q->front)
		printf("%d\n", MAX_QUEUE_SIZE - q->front + q->rear);
	else
		printf("%d\n", q->rear - q->front);
}

void ShowQueue(Queue* q) // int* queue, int front, int rear)
{
	int rear = q->rear;
	if (rear < q->front)
		rear += MAX_QUEUE_SIZE;

	printf("(front) ");
	for (int i = q->front + 1; i <= rear; i++)
		printf("%d ", q->q[i % MAX_QUEUE_SIZE]);
	printf("(rear)\n");
}
