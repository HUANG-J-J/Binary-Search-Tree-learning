#include "function.h"

//二叉排序树的建立
void Build_BST_1(BiTree& T,KeyType arr[],int len) {
	for (int i = 0; i < len; i++) {
		BST_insert_1(T, arr[i]);
	}
}

//二叉排序树的建立
bool BST_insert_1(BiTree& T, KeyType k) {
	BiTree TreeNew = (BSTNode*)calloc(1, sizeof(BSTNode));  //新结点申请空间
	if(TreeNew)
		TreeNew->key = k;   //把值存入结点中
	if (NULL == T) {
		T = TreeNew;      //新结点作为树的根
		return true;
	}
	BiTree p = T, parent=NULL; //p用来查找树
	while (p) {       //找到叶节点
		parent = p;   //存p的父结点
		if (k > p->key) {
			p = p->rchild;
		}
		else if (k < p->key) {
			p = p->lchild;
		}
		else {
			return false;  //相等的元素存入时，错误
		}
	}
	if (k > parent->key) {
		parent->rchild = TreeNew;
	}
	else {
		parent->lchild = TreeNew;
	}

	return true;
}

//二叉排序树的建立（递归）
void Build_BST_2(BiTree& T, KeyType arr[], int len) {
	for (int i = 0; i < len; i++) {
		BST_insert_2(T, arr[i]);
	}
}

//二叉排序树的建立（递归）
bool BST_insert_2(BiTree& T, KeyType k) {
	if (NULL == T) {
		T = (BSTNode*)calloc(1, sizeof(BSTNode));
		if(T)
			T->key = k;
		return true;
	}
	else if (k > T->key) {
		return BST_insert_2(T->rchild, k);
	}
	else if(k<T->key){
		return BST_insert_2(T->lchild, k);
	}
	else {
		return false;
	}
}

//中序遍历
void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->lchild);
		printf("%d ", T->key);
		InOrder(T->rchild);
	}
}