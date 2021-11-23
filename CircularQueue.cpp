#pragma warning(disable:4996)

#include <stdio.h>

#define MAX_QUEUE_SIZE 8

bool IsEmpty(int, int);
bool IsFull(int, int);
void Enqueue(int*, int*, int*, int);
void Dequeue(int*, int*, int*);
void Peek(int*, int);
void Size(int, int);
void Display(int*, int, int);

int main()
{
	int queue[MAX_QUEUE_SIZE] = { 0, }; // 저장할 수 있는 개수는 Size-1
	int front = 0; // 첫번째 요소 하나 앞의 인덱스, 새로운 값이 들어갈 수 없는 공간
	int rear = 0; // 마지막 요소의 인덱스

	for (int i = 1; i <= 8; i++)
		Enqueue(queue, &front, &rear, i);
	Display(queue, front, rear);
	Size(front, rear);

	Dequeue(queue, &front, &rear);
	Dequeue(queue, &front, &rear);
	Display(queue, front, rear);
	Size(front, rear);

	Enqueue(queue, &front, &rear, 8);
	Enqueue(queue, &front, &rear, 9);
	Enqueue(queue, &front, &rear, 10); //Fail
	Dequeue(queue, &front, &rear);
	Display(queue, front, rear);
	Size(front, rear);

	Enqueue(queue, &front, &rear, 10);
	Display(queue, front, rear);
	Size(front, rear);

	Enqueue(queue, &front, &rear, 11); // Fail
	Display(queue, front, rear);
	Size(front, rear);

	Peek(queue, front);
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
	if (front == (rear+1) % MAX_QUEUE_SIZE)
		return true;
	return false;
}

void Enqueue(int* queue, int* front, int* rear, int val)
{
	if (IsFull(*front, *rear))
	{
		printf("Queue if full : %d\n", val);
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
	printf("%d", queue[front+1]);
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
		printf("%d ", queue[i%MAX_QUEUE_SIZE]);
	printf("(rear)\n");
}