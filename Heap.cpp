#pragma warning(disable:4996)

#include <stdlib.h>
#include "queue.h"

#define MAX_HEAP_SIZE 16

void AddNode(int* heap, int* q, int data)
{

}

void DeleteNode(Tree* tree, int data)
{
	bool check = false;
	IsInTree(tree->root, data, &check);
	if (!check)
	{
		printf("* No Such Data : %d\n", data);
		return;
	}

	Node* target = tree->root;
	Node* tmp = NULL;
	while (1)
	{
		if (target->data > data)
		{
			if (target->left != NULL)
				if (target->left->data == data)
				{
					tmp = target->left;
					target->left = NULL;
					(target->degree)--;
					break;
				}
				else
					target = target->left;
		}
		else
		{
			if (target->right != NULL)
				if (target->right->data == data)
				{
					tmp = target->right;
					target->right = NULL;
					(target->degree)--;
					break;
				}
				else
					target = target->right;
		}
	}
	printf("* Delete :%d\n", tmp->data);
	FindTarget(tree, tmp->left, tmp->left->data);
	FindTarget(tree, tmp->right, tmp->right->data);
	(tree->size)--;
	free(tmp);
}

void SerachNode()
{

}

int main()
{
	int heap[MAX_HEAP_SIZE] = { 0, };
	int queue[MAX_QUEUE_SIZE] = { 0, };

	AddNode(heap, q, 13);
	return 0;
}