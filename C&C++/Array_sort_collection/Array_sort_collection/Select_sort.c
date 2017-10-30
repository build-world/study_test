//Copyright 2016 Fyf and Xjw. All Rights Reserved.

#include "custom.h"
#include <stdio.h>
#include <stdlib.h>

void Select_sort_1(Number *array, BitNum n)//Fyf 简单选择排序
{
	Number temp;
	BitNum i, j;//i指向有序区最接近无序区的元素,j遍历无序区寻找值最小交换对象
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (array[j] < array[i])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
}

void Select_sort_2(Number *array, BitNum n)//Fyf
{
	Number minimum, temp;
	BitNum cursor, i, objptr = 0;//cursor指向有序区最接近无序区的元素,i遍历无序区寻找值最小交换对象,objptr指向交换对象元素且需初始化
	for (cursor = 0; cursor < n - 1; cursor++)
	{
		minimum = array[cursor];
		for (i = cursor + 1; i < n; i++)
		{
			if (array[i] < minimum)
			{
				minimum = array[i];
				objptr = i;
			}
		}
		if (minimum == array[cursor]) continue;
		else
		{
			temp = array[cursor];
			array[cursor] = array[objptr];
			array[objptr] = temp;
		}
		//printf("\nfor debug cursor=%d\n", cursor);
		//PrintArray(array, n, 1);
	}
}
