//Copyright 2016 Fyf and Xjw. All Rights Reserved.

#include "custom.h"
#include <stdio.h>
#include <stdlib.h>

#define LeftChild(i)  (2*(i)+1)

void Swap(Number* a, Number* b)//Xjw
{
	Number temp = *b;
	*b = *a;
	*a = temp;
}

void Perc_Down(Number Arr[], BitNum i, BitNum Max)//Xjw
{
	Number Child;
	Number Tmp;
	for (Tmp = Arr[i]; LeftChild(i) < Max; i = Child)
	{
		Child = LeftChild(i);
		if (Child != Max - 1 && Arr[Child + 1] > Arr[Child])
			Child++;
		if (Tmp < Arr[Child])
			Arr[i] = Arr[Child];
		else
			break;
	}
	Arr[i] = Tmp;
}

void Heap_sort(Number *array, BitNum n)//Xjw
{
	BitNum i;
	for (i = n / 2; i >= 0; i--)//build heap
		Perc_Down(array, i, n);
	for (i = n - 1; i > 0; i--)
	{
		Swap(&array[0], &array[i]);//deleteMax
		Perc_Down(array, 0, i);
	}
}

//int main() {
//	int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
//	int len = (int) sizeof(arr) / sizeof(*arr);
//	Heapsort(arr, len);
//	int i;
//	for (i = 0; i < len; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//	system("pause");
//	return 0;
//}