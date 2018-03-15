#pragma once

typedef struct SeqStack
{
	int ctr;
	int limit;
	void ** base;
}SStack, *pSStack;

typedef struct LinkStack
{
	void * element;
	struct LinkStack * link;
}LStack, *pLStack;

typedef struct LinkStackHead
{
	int ctr;
	pLStack base;
}LSH, *pLSH;


extern void SeqStack_push(pSStack obj, void * ElemAddr);

extern void * SeqStack_pop(pSStack obj);

extern void LinkStack_push(pLSH obj, void * element);

extern void * LinkStack_pop(pLSH obj);
