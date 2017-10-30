//Copyright 2016 Fyf and Xjw. All Rights Reserved.

#include "custom.h"
#include <stdio.h>
#include <stdlib.h>

void Count_sort(Number *array, BitNum n)//Fyf
{
	Number offset;
	BitNum i;
	BitNum *temp = (BitNum *)calloc(MAX_NUM, sizeof(BitNum));
	for (i = 0; i < n; i++)
	{
		offset = array[i] - 0;
		temp[offset]++;
	}
	for (offset = 0, i = 0; offset < 100; offset++)
	{
		while (temp[offset] > 0)
		{
			array[i] = offset;
			temp[offset]--;
			i++;
		}
	}
}