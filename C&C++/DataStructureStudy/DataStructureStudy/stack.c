#include "stack.h"

void SeqStack_push(pSStack obj, void * ElemAddr)
{
	if (obj->ctr < obj->limit)
	{
		*(obj->base + obj->ctr) = ElemAddr;
		obj->ctr += 1;
	}
	return;
}

void * SeqStack_pop(pSStack obj)
{
	if (obj->ctr > 0)
	{
		obj->ctr -= 1;
		return *(obj->base + obj->ctr);
	}
	else
		return -1;
}

void LinkStack_push(pLSH obj, void * element)
{

}

void * LinkStack_pop(pLSH obj)
{

}
