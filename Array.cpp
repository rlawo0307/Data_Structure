#pragma warning(disable:4996)

#include <stdio.h>
#include "Sort.h"

void CreateArr(int*, int, int);
void PrintArr(int*, int, int);

int main()
{
	int arr1[10] = { 0, };
	int row, col;

	row = 1;
	col = sizeof(arr1) / sizeof(int);

	CreateArr(arr1, row, col);
	PrintArr(arr1, row, col);
	
	printf("\n==============================================================================================\n\n");

	int arr2[5][10] = { 0, };

	row = sizeof(arr2) / sizeof(arr2[0]);
	col = sizeof(arr2[0]) / sizeof(int);

	CreateArr(arr2[0], row, col);
	PrintArr(arr2[0], row, col);

	return 0;
}

void CreateArr(int* arr, int row, int col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			*(arr + i * col + j) = i * col + j;
}

void PrintArr(int* arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%d\t", *(arr + i * col + j));
		printf("\n");
	}
}
