#pragma warning(disable:4996)

#include <stdio.h>

#define MAX_QUEUE_SIZE 8

bool IsEmpty();
bool IsFull(int, int);
void AddFront();
void DelFront();
void AddRear();
void DelRear();
void GetFront();
void GetRear();
void Display(int*, int, int);

int main()
{
	int dq[MAX_QUEUE_SIZE] = { 0, }; 
	int front = 0; 
	int rear = 0; 
	int val = 1;
	int size;
}