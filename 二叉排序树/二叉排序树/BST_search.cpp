#include "function.h"

//¶ş²æÅÅĞòÊ÷µÄ²éÕÒ
bool BST_search(BiTree T, KeyType key, BiTree& p, BiTree& pos) {
	p = NULL;
	pos = T;
	while (pos != NULL && key != pos->key) {
		p = pos;
		if (key > pos->key) {
			pos = pos->rchild;
		}
		else if (key < pos->key) {
			pos = pos->lchild;
		}
	}
	if (pos == NULL) {
		printf("NOT FOUND!\n");
		return false;
	}
	printf("THE KEY IS %d.\n", pos->key);
	return true;
}