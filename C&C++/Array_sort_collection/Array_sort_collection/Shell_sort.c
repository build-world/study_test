//Copyright 2016 Fyf and Xjw. All Rights Reserved.

#include "custom.h"
#include <stdio.h>
#include <stdlib.h>

void Shell_sort_1(Number *array, BitNum n)//Fyf
{
	Number temp;
	BitNum d, head, group, cursor;//d为增量,按d分组,head指向每组头位元素,group遍历指向除头位元素的每组各元素,cursor指向插入过程每次的移位元素
	Counter ctr = 0;
	for (d = n / 2; d > 0; d /= 2)//选取增量d
	{
		for (head = 0; head < d; head++)//按d分组,head指向每组头位元素,每两个head差1,区间[0-(d-1)]
		{
			for (group = head + d; group < n; group += d)//每两个group差d,此后开始按组direct Insert sort
			{
				for (cursor = group; cursor > head && array[cursor] < array[cursor - d]; cursor -= d)//插入直到正确位置
				{
					temp = array[cursor];
					array[cursor] = array[cursor - d];
					array[cursor - d] = temp;
					ctr++;
				}
			}
			//printf("\nfor debug d=%d,head=%d\n", d, head);
			//PrintArray(array, n, 1);
			//system("pause");
		}
	}
	printf("\nCounter=%d\n", ctr);
}

void Shell_sort_2(Number *array, BitNum n)//网上的,对这算法有疑问
{
	Number temp;
	BitNum d, i, j;
	Counter ctr = 0;
	for (d = n / 2; d > 0; d /= 2)
	{
		for (i = d; i < n; i++)
		{
			for (j = i - d; j >= 0 && array[j] > array[j + d]; j -= d)
			{
				temp = array[j];
				array[j] = array[j + d];
				array[j + d] = temp;
				ctr++;
			}
			//printf("\nfor debug d=%d,i=%d\n", d, i);
			//PrintArray(array, n, 1);
			//system("pause");
		}
	}
	printf("\nCounter=%d\n", ctr);
}

