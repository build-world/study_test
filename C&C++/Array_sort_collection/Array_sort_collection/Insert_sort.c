//Copyright 2016 Fyf and Xjw. All Rights Reserved.

#include "custom.h"
#include <stdio.h>
#include <stdlib.h>

void Insert_sort_1(Number *array, BitNum n)//Fyf 插入元素逐个交换到正确位置
{
	Number temp;
	BitNum i, j;//i指向待插入元素
	for (i = 1; i < n; i++)
	{
		for (j = i; j > 0 && array[j] < array[j - 1]; j--)
		{
			temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
		}
		//printf("\nfor debug i=%d\n", i);
		//PrintArray(array, n, 1);
		//system("pause");
	}
}

void Insert_sort_2(Number *array, BitNum n)//Fyf 先遍历找到插入位置再插入
{
	Number temp;
	BitNum i, j, cursor;//i指向待插入元素,j遍历寻找并指向有序区第一个值大于待插入元素的元素,cursor倒序将包括j指向的元素的有序区元素向后移1数据位并覆盖i指向的待插入数据位，扩展有序区1数据位
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i && array[j] <= array[i]; j++);
		temp = array[i];
		cursor = i;
		for (cursor; cursor > j; cursor--)
		{
			array[cursor] = array[cursor - 1];
		}
		array[j] = temp;
	}
}