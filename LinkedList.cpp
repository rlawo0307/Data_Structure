#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int data;
	struct NODE* next;
}Node;

void AddNode(Node*, int, int*);
void AddNode(Node*, int, int, int*);
void DeleteNode(Node*, int, int*);
void SearchNode(Node*, int, int);
void PrintList(Node*);

int main()
{
	Node* head = (Node*)calloc(sizeof(Node), 1); //dummy
	int cnt = 0;

	AddNode(head, 10, &cnt);
	PrintList(head);
	
	AddNode(head, 2, 20, &cnt);
	PrintList(head);
	
	AddNode(head, 4, 40, &cnt); // Fail

	AddNode(head, 3, 30, &cnt);
	AddNode(head, 4, 40, &cnt);
	PrintList(head);

	DeleteNode(head, 2, &cnt);
	PrintList(head);

	DeleteNode(head, 4, &cnt); // Fail

	SearchNode(head, 3, cnt);
	SearchNode(head, 4, cnt); // Fail
}

void AddNode(Node* head, int val, int* cnt)
{
	Node* np = head;

	while (np->next != NULL)
		np = np->next;

	np->next = (Node*)calloc(sizeof(Node), 1);
	np = np->next;
	np->data = val;

	(*cnt)++;
}

void AddNode(Node* head, int index, int val, int* cnt)
{
	Node* np = head;

	for (int i = 1; i < index; i++)
	{
		np = np->next;
		if (np == NULL)
		{
			printf("Add Fail (Last Index : %d, Requested Index : %d)\n", *cnt, index);
			return;
		}
	}
	np->next = (Node*)calloc(sizeof(Node), 1);
	np = np->next;
	np->data = val;
	(*cnt)++;
}

void DeleteNode(Node* head, int index, int* cnt)
{
	Node* np = head;
	Node* prev = head;

	if (index > *cnt)
	{
		printf("Delete Fail (Last Index : %d, Reqeusted Index : %d)\n", *cnt, index);
		return;
	}

	for (int i = 0; i < index - 1; i++)
		prev = prev->next;
	np = prev->next;

	prev->next = np->next;
	free(np);
	(*cnt)--;
}

void SearchNode(Node* head, int index, int cnt)
{
	Node* np = head;

	if (index > cnt)
	{
		printf("Delete Fail (Last Index : %d, Reqeusted Index : %d)\n", cnt, index);
		return;
	}

	for (int i = 0; i < index; i++)
		np = np->next;
	printf("index %d : %d\n", index, np->data);
}

void PrintList(Node* head)
{
	Node* np = head;

	while (np != NULL)
	{
		printf("%d", np->data);
		np = np->next;
		if (np != NULL)
			printf(" -> ");
	}
	printf("\n");
}