#include "tree.h"

pBTN BuildBiTree(unsigned int num)
{
	int layer, ctr, layer_ctr;//root node at layer 0, ctr record current amount of node, layer_ctr record amount of node in current layer.
	pBTN root = (pBTN)malloc(sizeof(BTN));
	root->element = NULL;
	root->lchild = NULL;
	root->rchild = NULL;
	root->parent = NULL;
	layer = 1, ctr = 1, layer_ctr = 0;
	while (ctr < num)

	return root;
}