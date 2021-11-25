#pragma warning(disable:4996)

#include <stdio.h>
#include "Queue.h"

#define MAX_HEAP_SIZE 16

void Display(int* heap, int cnt)
{
	for (int i = 0; i <= cnt; i++)
		printf("%d ", heap[i]);
	printf("\n");
}

void Swap(int* heap, int i, int j)
{
	int tmp = heap[i];
	heap[i] = heap[j];
	heap[j] = tmp;
}

void AddNode(int* heap, int data, int* cnt)
{
	if (*cnt == 0) // root
	{
		(*cnt)++;
		heap[*cnt] = data;
		return;
	}
	else
	{
		int cur = *cnt + 1;
		int parent;

		heap[cur] = data;

		parent = cur / 2;
		while (heap[parent] <= heap[cur] && cur > 1)
		{
			Swap(heap, parent, cur);
			cur = parent;
			parent = cur / 2;
		}
		(*cnt)++;
	}
}

void DeleteNode(int* heap, int* cnt)
{
	int cur, child;

	Swap(heap, 1, *cnt);
	heap[(*cnt)--] = 0;

	cur = 1;
	child = cur * 2;
	while (heap[cur] < heap[child] && child <= *cnt)
	{
		Swap(heap, cur, child);
		cur = child;
		child = cur * 2;
	}
}

void SerachNode(int* heap, int data)
{
	int cur;

	Queue* q = (Queue*)calloc(sizeof(Queue), 1);
	InitQueue(q);
	Enqueue(q, 1); // root
	while (1)
	{
		cur = Dequeue(q);
		if (cur == -1)
		{
			printf("No Such Data : %d\n", data);
			return;
		}
		if (heap[cur] == data)
		{
			printf("heap[%d] = %d\n", cur, heap[cur]);
			return;
		}
		else if (heap[cur] > data)
		{
			Enqueue(q, cur*2); // left
			Enqueue(q, cur * 2 + 1); // right
		}
	}
}

int main()
{
	int heap[MAX_HEAP_SIZE] = { 0, };
	int cnt = 0;

	for (int i = 13; i >= 1; i--)
		AddNode(heap, i, &cnt);
	Display(heap, cnt);
	DeleteNode(heap, &cnt);
	Display(heap, cnt);

	SerachNode(heap, 1);
	SerachNode(heap, 34);
	return 0;
}