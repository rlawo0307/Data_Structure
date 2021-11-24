#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int data;
	int depth;
	int degree;
	int size; // Only root
	struct NODE* parent;
	struct NODE* left;
	struct NODE* right;
}Node;

bool IsEmtpy();
void CreateTree(Node*, Node*, int);
void preorderTraverse(Node*); // 전위 순회
void inorderTraverse(Node*); // 중위 순회
void postorderTraverse(Node*); // 후위 순회

int main()
{
	Node* root = (Node*)calloc(sizeof(Node), 1);
	if (root == NULL)
	{
		printf("Calloc Fail\n");
		return -1;
	}
	root->size = 1;

	CreateTree(root, root, 1);
	preorderTraverse(root);
	//inorderTraverse(root);
	//postorderTraverse(root);

	printf("\nsize : %d\n", root->size);
}

void CreateTree(Node* root, Node* parent, int val)
{

	Node* tmp = (Node*)calloc(sizeof(Node), 1);
	if (tmp == NULL)
	{
		printf("Calloc Fail\n");
		return;
	}
	tmp->data = val;
	tmp->parent = parent;
	tmp->depth = tmp->parent->depth + 1;
	(tmp->parent->degree)++;
	if (tmp->parent->left == NULL)
		tmp->parent->left = tmp;
	else
		tmp->parent->right = tmp;
	(root->size)++;
}

void preorderTraverse(Node* node)
{
	if (node == NULL)
		return;

	printf("%d ", node->data);

	preorderTraverse(node->left);
	preorderTraverse(node->right);
}