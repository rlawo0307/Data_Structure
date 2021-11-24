#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int data;
	int depth;
	int degree;
	struct NODE* parent;
	struct NODE* left;
	struct NODE* right;
}Node;

typedef struct TREE
{
	Node* root;
	int size;
	int degree;
	int height;
}Tree;


void InitTree(Tree* tree)
{
	tree->root = NULL;
}

bool IsInTree(Tree* tree, int data)
{
	Node* target = tree->root;
	while (target != NULL)
	{
		if (target->data == data)
			return true;
		if (target->data > data)
			target = target->left;
		else
			target = target->right;
	}
	return false;
}

void FindTarget(Tree* tree, Node* cur, int data)
{
	if (cur == NULL)
		return;

	Node* parent = tree->root;
	while (1)
	{
		if (parent->data > data)
			if (parent->left == NULL)
			{
				parent->left = cur;
				break;
			}
			else
				parent = parent->left;
		else
			if (parent->data < data)
				if (parent->right == NULL)
				{
					parent->right = cur;
					break;
				}
				else
					parent = parent->right;
	}
	cur->parent = parent;
	cur->depth = parent->depth + 1;
	(parent->degree)++;
	if (parent->degree > tree->degree)
		tree->degree = parent->degree;
	if (cur->depth > tree->height)
		tree->height = cur->depth;
}

void AddNode(Tree* tree, int data)
{
	if (IsInTree(tree, data)) // 중복 허용하지 않음
	{
		printf("* Already exist : %d\n", data);
		return;
	}

	Node* tmp = (Node*)calloc(sizeof(Node), 1);
	if (tmp == NULL)
	{
		printf("Calloc Fail\n");
		return;
	}
	tmp->data = data;
	
	if (tree->root == NULL)
		tree->root = tmp;
	else
		FindTarget(tree, tmp, data);
	(tree->size)++;

	printf("* Add : %d\n", tmp->data);
}

void DeleteNode(Tree* tree, int data)
{
	if (!IsInTree(tree, data))
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

void PreOrderTraverse(Node* node)
{
	if (node == NULL)
		return;

	printf("%d ", node->data);

	PreOrderTraverse(node->left);
	PreOrderTraverse(node->right);
}

int main()
{
	Tree* tree = (Tree*)calloc(sizeof(Tree), 1);
	if (tree == NULL)
	{
		printf("Calloc Fail\n");
		return -1;
	}
	InitTree(tree);

	AddNode(tree, 30);
	AddNode(tree, 10);
	AddNode(tree, 40);
	AddNode(tree, 24);
	AddNode(tree, 14);
	AddNode(tree, 26);
	AddNode(tree, 46);
	AddNode(tree, 10); // Already exist
	AddNode(tree, 14); // Already exist
	printf("\n");
	PreOrderTraverse(tree->root); // 전위 순회

	printf("\nsize : %d degree : %d height : %d\n\n", tree->size, tree->degree, tree->height);

	DeleteNode(tree, 24);
	printf("\n");
	PreOrderTraverse(tree->root); // 전위 순회
	printf("\nsize : %d degree : %d height : %d\n\n", tree->size, tree->degree, tree->height);
	
	DeleteNode(tree, 54); // Fail

	IsInTree(tree, 54); //Fail
	return 0;
}