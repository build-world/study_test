//Copyright 2016 Fyf and Xjw. All Rights Reserved.

#include "custom.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintArray(Number *array, BitNum n, int flag)//Fyf
{
	for (BitNum i = 0; i < n; i++)
	{
		if(flag == 0) printf("%d\n", array[i]);
		else printf("array[%d]=%d\n", i, array[i]);
	}
}

Number* getRandomArray(BitNum n, Number maximum)//Fyf
{
	BitNum i;
	Number *array = (Number *)calloc(n, sizeof(Number));
	srand(time(0));
	for (i = 0; i < n; i++)
	{
		array[i] = rand() % maximum;
	}
	return array;
}

BitNum verify(Number *array, BitNum n)//Fyf
{
	BitNum i;
	for (i = 0; array[i] <= array[i + 1] && i < n - 1; i++);
	return i + 1;
}