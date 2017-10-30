//Copyright 2016 Fyf and Xjw. All Rights Reserved.

#include "custom.h"
#include <stdio.h>
#include <stdlib.h>

//iteration
void Merge_sort_iteration(Number *array, BitNum n)//Fyf
{
	BitNum step, half_step_l, half_step_r, cursor, team_num, lpoi, rpoi, ctr, left, temp, i;
	int flag;//small tail flag
	for (step = 2; step <= n; step *= 2)
	{
		team_num = n / step;
		left = n % step;
		flag = 0;
		for (ctr = 1, cursor = 0; ctr <= team_num; ctr++, cursor += step)
		{
			half_step_l = step / 2;
			half_step_r = step / 2;
			lpoi = cursor;
		    rpoi = cursor + half_step_l;
			if (ctr == team_num && left != 0)
			{
				flag = 1;
				temp = step + left;
			}
			else
			{
				temp = step;
			}
			Number *arr = (Number *)calloc(temp, sizeof(Number));
			if (flag == 1)
			{
				for (i = 0; i < step; i++)
				{
					if (lpoi - cursor == half_step_l - 1 && rpoi - (cursor + half_step_l) == half_step_r - 1)
					{
						if (array[lpoi] <= array[rpoi])
						{
							arr[i] = array[lpoi];
							arr[i + 1] = array[rpoi];
						}
						else
						{
							arr[i] = array[rpoi];
							arr[i + 1] = array[lpoi];
						}
						break;
					}
					else if (lpoi - cursor == half_step_l)
					{
						arr[i] = array[rpoi];
						rpoi++;
					}
					else if (rpoi - (cursor + half_step_l) == half_step_r)
					{
						arr[i] = array[lpoi];
						lpoi++;
					}
					else
					{
						if (array[lpoi] <= array[rpoi])
						{
							arr[i] = array[lpoi];
							lpoi++;
						}
						else
						{
							arr[i] = array[rpoi];
							rpoi++;
						}
					}
				}
				for (i = 0; i < step; i++)
				{
					array[cursor + i] = arr[i];
				}
				half_step_l = half_step_l + half_step_r;
				half_step_r = left;
				lpoi = cursor;
				rpoi = cursor + half_step_l;
				for (i = 0; i < temp; i++)
				{
					if (lpoi - cursor == half_step_l - 1 && rpoi - (cursor + half_step_l) == half_step_r - 1)
					{
						if (array[lpoi] <= array[rpoi])
						{
							arr[i] = array[lpoi];
							arr[i + 1] = array[rpoi];
						}
						else
						{
							arr[i] = array[rpoi];
							arr[i + 1] = array[lpoi];
						}
						break;
					}
					else if (lpoi - cursor == half_step_l)
					{
						arr[i] = array[rpoi];
						rpoi++;
					}
					else if (rpoi - (cursor + half_step_l) == half_step_r)
					{
						arr[i] = array[lpoi];
						lpoi++;
					}
					else
					{
						if (array[lpoi] <= array[rpoi])
						{
							arr[i] = array[lpoi];
							lpoi++;
						}
						else
						{
							arr[i] = array[rpoi];
							rpoi++;
						}
					}
				}
			}
			else
			{
				for (i = 0; i < temp; i++)
				{
					if (lpoi - cursor == half_step_l - 1 && rpoi - (cursor + half_step_l) == half_step_r - 1)
					{
						if (array[lpoi] <= array[rpoi])
						{
							arr[i] = array[lpoi];
							arr[i + 1] = array[rpoi];
						}
						else
						{
							arr[i] = array[rpoi];
							arr[i + 1] = array[lpoi];
						}
						break;
					}
					else if (lpoi - cursor == half_step_l)
					{
						arr[i] = array[rpoi];
						rpoi++;
					}
					else if (rpoi - (cursor + half_step_l) == half_step_r)
					{
						arr[i] = array[lpoi];
						lpoi++;
					}
					else
					{
						if (array[lpoi] <= array[rpoi])
						{
							arr[i] = array[lpoi];
							lpoi++;
						}
						else
						{
							arr[i] = array[rpoi];
							rpoi++;
						}
					}
				}
			}
			for (i = 0; i < temp; i++)
			{
				array[cursor + i] = arr[i];
			}
			free(arr);
			//printf("\nfor debug step=%d,cursor=%d,half_step_l=%d,half_step_r=%d\n", step, cursor, half_step_l, half_step_r);
			//PrintArray(array, n, 1);
			//system("pause");
		}
	}
}


//recursion
void Do_merge(Number *Array, Number *TmpArray, BitNum p1, BitNum p2, BitNum end2)//Xjw
{
	BitNum end1, tmpp, num, i;
	end1 = p2 - 1;
	tmpp = p1;
	num = end2 - p1 + 1;

	while (p1 <= end1 && p2 <= end2) {
		if (Array[p1] <= Array[p2])
			TmpArray[tmpp++] = Array[p1++];
		else
			TmpArray[tmpp++] = Array[p2++];
	}
	while (p1 <= end1)
		TmpArray[tmpp++] = Array[p1++];
	while (p2 <= end2)
		TmpArray[tmpp++] = Array[p2++];

	for (i = 0; i < num; i++, end2--)
		Array[end2] = TmpArray[end2];
}

void Split_merge(Number *Array, Number *TmpArray, BitNum Left, BitNum Right)//Xjw
{
	int Center;
	if (Left < Right) {
		Center = (Left + Right) / 2;
		Split_merge(Array, TmpArray, Left, Center);
		Split_merge(Array, TmpArray, Center + 1, Right);
		Do_merge(Array, TmpArray, Left, Center + 1, Right);
	}
}

void Merge_sort_recursion(Number *array, BitNum n)//Xjw
{
	Number *TmpArray;
	TmpArray = malloc(n * sizeof(Number));
	Split_merge(array, TmpArray, 0, n - 1);
	free(TmpArray);
}