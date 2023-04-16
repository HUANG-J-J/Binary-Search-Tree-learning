#include "function.h"

int main() {
	BiTree T1 = NULL;
	BiTree T2 = NULL;
	BiTree parent;
	BiTree search;
	KeyType arr[7] = { 54,20,66,40,28,79,58 };

	Build_BST_1(T1, arr, 7);
	InOrder(T1);
	BST_search(T1, 41, parent, search);

	Build_BST_2(T2, arr, 7);
	InOrder(T2);
	BST_search(T2, 40, parent, search);

	BST_del(T1, 4);
	InOrder(T1);

	return 0;
}