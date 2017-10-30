//Copyright 2016 Fyf and Xjw. All Rights Reserved.

#include "custom.h"
#include <stdio.h>
#include <stdlib.h>

void Quick_sort_1(Number *array, BitNum n)//Fyf
{
	Number pivot = array[0];
	BitNum i = 0, j = n - 1;
	while (i < j)
	{
		while (i < j && array[j] >= pivot) j--;//"="is optional
		if (i < j)
		{
			array[i] = array[j];
			i++;
		}
		while (i < j && array[i] <= pivot) i++;//"="is optional
		if (i < j)
		{
			array[j] = array[i];
			j--;
		}
	}
	array[i] = pivot;
	//printf("\nfor debug\n");
	//PrintArray(array, n, 1);
	//printf("0x%x && 0x%x\n", array, array + i + 1);
	//system("pause");
	if (i > 1)  Quick_sort_1(array, i);
	if (n - 1 - i > 1)  Quick_sort_1(array + i + 1, n - 1 - i);
}

void Quick_sort_2(Number *array, BitNum n)//Fyf
{
	Number pivot = array[0];
	BitNum i = 0, j = n - 1;
	while (i < j)
	{
		while (i < j && array[j] >= pivot) j--;//"="is nessesary,if i =1 to n,count(array[i]==pivot) > 1
		if (i < j) array[i] = array[j];
		while (i < j && array[i] <= pivot) i++;//"="is nessesary,if i =1 to n,count(array[i]==pivot) > 1
		if (i < j) array[j] = array[i];
	}
	array[i] = pivot;
	//printf("\nfor debug\n");
	//PrintArray(array, n, 1);
	//printf("0x%x && 0x%x\n", array, array + i + 1);
	//system("pause");
	if (i > 1)  Quick_sort_2(array, i);
	if (n - 1 - i > 1)  Quick_sort_2(array + i + 1, n - 1 - i);
}