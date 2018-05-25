#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef int CTR_LEVEL;
typedef int CTR_STEP;
typedef int CTR_TOWER;

CTR_STEP CalcTotalStep(CTR_LEVEL level);
void Hanoi_recursion(CTR_LEVEL level, CTR_TOWER src, CTR_TOWER dest);
void Hanoi_iteration(CTR_LEVEL level, CTR_TOWER src, CTR_TOWER dest);
