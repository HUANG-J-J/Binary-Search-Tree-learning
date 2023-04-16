#include "function.h"

void BST_del(BiTree& T, KeyType x) {
	if (NULL == T) return;
	if (T->key > x) {
		BST_del(T->lchild, x);
	}
	else if (T->key < x) {
		BST_del(T->rchild, x);
	}
	else {
		if (NULL == T->lchild && NULL == T->rchild) {
			free(T);
		}
		else if (NULL == T->lchild) {
			BiTree tempNode = T;
			T = T->rchild;
			free(tempNode);
		}
		else if (NULL == T->rchild) {
			BiTree tempNode = T;
			T = T->lchild;
			free(tempNode);
		}
		else {
			BiTree tempNode = T->lchild;
			while (tempNode->rchild != NULL)
				tempNode = tempNode->rchild;
			T->key = tempNode->key;
			BST_del(T->lchild, tempNode->key);
		}
	}
}