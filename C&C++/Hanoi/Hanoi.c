#include "Hanoi.h"

CTR_STEP CalcTotalStep(CTR_LEVEL level)//res = 2^level - 1
{
	int sum = 0;
	for (int ctr = 0, ite = 1; ctr < level; sum += ite, ite <<= 1, ctr++);
	return sum;
}

void Hanoi_recursion(CTR_LEVEL level, CTR_TOWER src, CTR_TOWER dest)
{
	//CTR_STEP TotalStep = CalcTotalStep(level);
	CTR_TOWER buffer = 1;
	for (; buffer == src || buffer == dest; buffer++);
	if (level > 1)
	{
		//pre bottom mov
		Hanoi_recursion(level - 1, src, buffer);
		//
		printf("(%d) %d -> %d\n", level, src, dest);
		//post bottom mov
		Hanoi_recursion(level - 1, buffer, dest);
	}
	else
	{
		printf("(%d) %d -> %d\n", level, src, dest);
	}
}

void Hanoi_iteration(CTR_LEVEL level, CTR_TOWER src, CTR_TOWER dest)
{
	
}
