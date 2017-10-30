//Copyright 2016 Fyf and Xjw. All Rights Reserved.

#include "custom.h"
#include <stdio.h>
#include <stdlib.h>

void Bubble_sort(Number *array, BitNum n)//Fyf
{
	BitNum otr, inr;
	Number temp;
	for (otr = n -1; otr >= 0; otr--)
	{
		for (inr = 0; inr < otr; inr++)
		{
			if (array[inr] > array[inr + 1])
			{
				temp = array[inr];
				array[inr] = array[inr + 1];
				array[inr + 1] = temp;
			}
		}
		//printf("\nfordebug round%d\n", n - otr);
		//PrintArray(array, n, 1);
	}
}

void Bubble_sort_dual_1(Number *array, BitNum n)//Fyf
{
	BitNum i, head = 0, rear = n - 1;
	Number temp;
	//long test = 0;
	while (rear - head > 1)//outer loop
	{
		for (i = head; i < rear; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
		rear--;
		//printf("\nfor debug round%d\nhead=%d rear=%d\n", ++test, head, rear);
		//PrintArray(array, n, 1);
		for (i = rear; i > head; i--)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
			}
		}
		head++;
		//printf("\nfor debug round%d\nhead=%d rear=%d\n", ++test, head, rear);
		//PrintArray(array, n, 1);
	}
}

void Bubble_sort_dual_2(Number *array, BitNum n)//Fyf
{
	BitNum i, head = 0, rear = n - 1, counter;
	Number temp;
	for (counter = 0; rear - head > 1; counter++)//outer loop
	{
		//inner loop start***********************************
		if (counter % 2 == 0)//向上冒泡偶操作
		{
			for (i = head; i < rear; i++)
			{
				if (array[i] > array[i + 1])
				{
					temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
				}
			}
			rear--;
		}
		else//向下沉泡奇操作
		{
			for (i = rear; i > head; i--)
			{
				if (array[i - 1] > array[i])
				{
					temp = array[i - 1];
					array[i - 1] = array[i];
					array[i] = temp;
				}
			}
			head++;
		}
		//inner loop end*************************************
	}
}