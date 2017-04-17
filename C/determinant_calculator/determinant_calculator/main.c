//Copyright 2016 Fyf All rights reserved.

/*
说明：行列式根据定义求值计算器
*
create_date:2016/06/04
*
last_edit_date:2016/06/04
*/

//==================/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//==================/
typedef int Number;
typedef int RCNum;
typedef int COUNTER;
typedef int FLAG;
//=================================================================================/
RCNum Input2mem(Number **poi);
void Print_det(RCNum n, Number *det);
Number Calc_det_dictionary(RCNum n, Number *det);
Number Calc_det_recursion(RCNum n, Number *det);
void recursion_proc(RCNum n, Number *det, Number *mul_ptr, RCNum *list, RCNum deep);
//=================================================================================/
int main()
{
	Number result_1, result_2, *det = NULL;
	RCNum n;
	clock_t t1, t2, t3;
	n = Input2mem(&det);//call by reference,把指针变量det的地址作为传递给形参
	printf("\n");
	Print_det(n, det);
	printf("\ncalculate_start\n");
	t1 = clock();
	result_1 = Calc_det_dictionary(n, det);
	t2 = clock();
	result_2 = Calc_det_recursion(n, det);
	t3 = clock();
	printf(
		"\ncalculate_finish\n\nCalc_det_dictionary=%d,use time %ldms\n\nCalc_det_recursion=%d,use time %ldms\n\n", 
		result_1, 
		t2 - t1, 
		result_2, 
		t3 - t2
	);
	free(det);
	system("pause");
	return 0;
}

RCNum Input2mem(Number **poi)//二级指针变量poi的指针指向指针变量det(main()中的)
{
	RCNum n, i, r, c;
	printf("input n\n");
	scanf_s("%d", &n);
	Number *det = calloc(n*n, sizeof(Number));
	*poi = det;//此处指针变量poi的取值结果即为指针变量det(main()中的)
	printf("please input\n");
	for (i = 0, r = 0, c = 0; i < n*n; i++)
	{
		r = i / n;
		c = i - r * n;
		printf("input r[%d]c[%d]=", r + 1, c + 1);
		scanf_s("%d", det + i);
	}
	return n;
}

void Print_det(RCNum n, Number *det)
{
	RCNum i;
	printf("Print_determinant:\n");
	for (i = 0; i < n*n; i++)
	{
		printf("%d", det[i]);
		if ((i + 1) % n == 0) printf("\n");
		else printf(" ");
	}
}

Number Calc_det_dictionary(RCNum n, Number *det)
{
	RCNum r, c, bit, set;
	RCNum *list = (RCNum *)calloc(n, sizeof(RCNum));
	Number add = 0, inv_num = 0, mul = 1;
	COUNTER ctr;
	FLAG cbflag = 0, addflag = 0, sign = 1;//进位flag
	for (bit = 0; bit < n; bit++) list[bit] = n - bit;
	for (ctr = 0;; ctr++)
	{
		//=================================================================/	
		if (ctr != 0)
		{
			bit = 0;//递增
			list[bit]++;
		}
		if (list[bit] > n)//溢出进位
		{
			list[bit] -= n;
			for (bit = 1, cbflag = 1; bit < n; bit++)
			{
				if (cbflag)
				{
					cbflag = 0;
					list[bit]++;
				}
				if (list[bit] > n)
				{
					list[bit] -= n;
					cbflag = 1;
				}
			}
			if (cbflag) break;//
		}//end
		//=================================================================/
		for (bit = 0, addflag = 1; bit < n; bit++)//累加条件判断
		{
			for (set = 0; set < n; set++)
			{
				if (bit == set) continue;
				if (list[bit] == list[set])
				{
					addflag = 0;
					break;
				}
			}
			if (addflag == 0) break;
		}//end
		//=================================================================/
		if (addflag)//累加
		{
			for (bit = 0, inv_num = 0; bit < n; bit++)//求逆序数得符号
			{
				for (set = bit + 1; set < n; set++)
				{
					if (list[bit] > list[set]) inv_num++;
				}
			}
			if (inv_num % 2 == 1) sign = -1;
			else sign = 1;//end
			//=============================================================/
			for (r = 0, mul = sign; r < n; r++)//不同行列累乘
			{
				c = list[r] - 1;
				mul *= det[r * n + c];
			}
			add += mul;//end
		}//end
	}
	free(list);
	return add;
}

Number Calc_det_recursion(RCNum n, Number *det)
{
	Number add = 0;
	RCNum cursor;
	RCNum *record = (RCNum *)calloc(n*n, sizeof(RCNum));
	for (cursor = 0; cursor < n; cursor++)
	{
		*(record + n*cursor) = cursor + 1;
		recursion_proc(n, det, &add, record + n*cursor, 0);
	}
	free(record);
	return add;
}

void recursion_proc(RCNum n, Number *det, Number *add_ptr, RCNum *list, RCNum deep)
{
	RCNum num, cursor, set, r, c;
	Number inv_num, mul = 1;
	FLAG jmp_flag = 0, add_flag = 0, sign = 1;
	//============================================================================/
	for (num = 1; num <= n; num++)//遍历取值全排列
	{
		for (cursor = 0; cursor <= deep; cursor++)
		{
			if (list[cursor] == num)
			{
				jmp_flag = 1;
				break;
			}
		}
		if (jmp_flag)
		{
			jmp_flag = 0;
			continue;
		}
		list[deep + 1] = num;
		if (deep + 1 == n - 1)
		{
			add_flag = 1;
			break;
		}
		recursion_proc(n, det, add_ptr, list, deep + 1);
	}//end
	//============================================================================/
	if (add_flag)//累加
	{
		add_flag = 0;
		for (cursor = 0, inv_num = 0; cursor < n; cursor++)//求逆序数得符号
		{
			for (set = cursor + 1; set < n; set++)
			{
				if (list[cursor] > list[set]) inv_num++;
			}
		}
		if (inv_num % 2 == 1) sign = -1;
		else sign = 1;//end
		for (r = 0, mul = sign; r < n; r++)//不同行列累乘
		{
			c = list[r] - 1;
			mul *= det[r * n + c];
		}
		*add_ptr += mul;//end
	}//end
}