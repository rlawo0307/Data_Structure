#pragma warning(disable:4996)

#include <stdio.h>
#include "Queue.h"

#define n 9
#define MAX_DATA_LENGHT 4

void Display(int* arr)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void Swap(int* arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

//시간복잡도 : O(N^2)
//공간복잡도 : O(N)
void SelectionSort(int* arr)
{
	for (int i = 0; i < n; i++)
	{
		int tmp = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[tmp])
				tmp = j;
		Swap(arr, i, tmp);
	}
}


//시간복잡도 : O(N^2)
//공간복잡도 : O(N)
void InsertionSort(int* arr)
{
	for (int i = 1; i < n; i++)
	{
		int tmp = i;
		for (int j = i - 1; j >= 0; j--)
			if (arr[tmp] >= arr[j])
				break;
			else
			{
				Swap(arr, tmp, j);
				tmp = j;
			}
	}
}

//시간복잡도 : O(N^2)
//공간복잡도 : O(N)
void BubbleSort(int* arr)
{
	for (int i = 0; i < n; i++)
		for (int j = 1; j < n; j++)
			if (arr[j - 1] > arr[j])
				Swap(arr, j - 1, j);
}

//시간복잡도 : O(NlogN)
//공간복잡도 : O(2N) = O(N)
void Merge(int* arr, int start, int end, int middle)
{
	int res[n] = { 0, };
	int i = start, j = middle + 1, cnt = 0;

	while (i <= middle && j <= end)
	{
		if (arr[i] < arr[j])
			res[cnt++] = arr[i++];
		else
			res[cnt++] = arr[j++];
	}
	while (i <= middle)
		res[cnt++] = arr[i++];
	while (j <= end)
		res[cnt++] = arr[j++];

	for (int k = 0; k < cnt; k++)
		arr[start + k] = res[k];
}

void MergeSort(int* arr, int start, int end)
{
	if (start >= end)
		return;

	int middle = (start + end) / 2;

	MergeSort(arr, start, middle);
	MergeSort(arr, middle +1, end);
	Merge(arr, start, end, middle);
}


//시간복잡도 : O(NlogN)
//이미 정렬되어 있는 경우 시간복잡도 : O(N^2)
//이를 방지하기 위해 pivot을 중간값이나 랜덤값으로 설정
void QuickSort(int* arr, int start, int end)
{
	if (start >= end)
		return;
	
	int pivot = start;
	int left = pivot + 1, right = end;

	while (1)
	{
		while (arr[left] < arr[pivot])
			left++;
		while (arr[right] > arr[pivot])
			right--;
		if (left > right)
		{
			Swap(arr, pivot, right);
			pivot = right;
			break;
		}
		Swap(arr, left, right);
	}
	QuickSort(arr, start, pivot - 1);
	QuickSort(arr, pivot + 1, end);
}

//시간복잡도 : O(NW)
//W = 데이터 길이
void RadixSort(int* arr)
{
	Queue* q = (Queue*)calloc(sizeof(Queue), 10);
	if (q == NULL)
	{
		printf("Calloc Fail\n");
		return;
	}
	for (int i = 0; i < 10; i++)
		InitQueue(&q[i]);

	int div = 1;
	for (int i = 1; i <= MAX_DATA_LENGHT; i++, div *= 10)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			int q_index = (arr[j] % (div * 10)) / div;
			Enqueue(&(q[q_index]), arr[j]);
		}
		for (int j = 0; j < 10; j++)
		{
			int tmp;
			while ((tmp = Dequeue(&(q[j]))) != -1)
				arr[cnt++] = tmp;
		}
	}
}

void InitArr(int* arr)
{
	arr[0] = 152;
	arr[1] = 73;
	arr[2] = 69;
	arr[3] = 41;
	arr[4] = 28;
	arr[5] = 1247;
	arr[6] = 2;
	arr[7] = 33;
	arr[8] = 674;
}

int main()
{
	int arr[n] = { 0, };

	printf("\n[ Selection Sort ]\n");
	InitArr(arr);
	Display(arr);
	SelectionSort(arr);
	Display(arr);

	printf("\n[ Insertion Sort ]\n");
	InitArr(arr);
	Display(arr);
	InsertionSort(arr);
	Display(arr);

	printf("\n[ Bubble Sort ]\n");
	InitArr(arr);
	Display(arr);
	BubbleSort(arr);
	Display(arr);

	printf("\n[ Merge Sort ]\n");
	InitArr(arr);
	Display(arr);
	MergeSort(arr, 0, n-1);
	Display(arr);

	printf("\n[ Quick Sort ]\n");
	InitArr(arr);
	Display(arr);
	QuickSort(arr, 0, n - 1);
	Display(arr);

	printf("\n[ Radix Sort ]\n");
	InitArr(arr);
	Display(arr);
	RadixSort(arr);
	Display(arr);

	return 0;
}