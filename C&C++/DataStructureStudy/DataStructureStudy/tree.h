#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct BiTreeNode
{
	void * element;
	struct BiTreeNode * lchild;
	struct BiTreeNode * rchild;
	struct BiTreeNode * parent;
}BTN, *pBTN;

pBTN BuildBiTree(unsigned int num);