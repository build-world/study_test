#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Hanoi.h"


int main()
{
	CTR_LEVEL level;
	CTR_STEP TotalStep;
	scanf("%d", &level);
	TotalStep = CalcTotalStep(level);
	printf("Total step: %d\n", TotalStep);
	Hanoi_recursion(level, 1, 3);
	//Alloc
	system("pause");
	return 0;
}