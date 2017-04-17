#include "custom.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	for (int i = 0; i < 100; i++)
	{
		clock_t r2s, s2f;
		int *array = getRandomArray(MAX_BIT, MAX_NUM);
		int *af = array;
		//int array[10] = { 40, 49, 64, 63, 53, 84, 48, 38, 47, 15 };
		printf("source data complete\n");
		//PrintArray(array, MAX_BIT, 0);
		system("pause");
		printf("\n\n\n");
//******************************************************************
		printf("sort start\n");
		r2s = clock();//timer start
		Quick_sort_1(array, MAX_BIT);
		s2f = clock();//time stop
		printf("sort finish,use time %ldms\n", s2f - r2s);
//******************************************************************
		printf("\n\n\n");
		//printf("sort_result\n");
		//PrintArray(array, MAX_BIT, 0);
		if (verify(array, MAX_BIT) == MAX_BIT)
			printf("result correct\n");
		else
			printf("result error\n");
		system("pause");
		free(af);
	}
	system("pause");
	return 0;
}