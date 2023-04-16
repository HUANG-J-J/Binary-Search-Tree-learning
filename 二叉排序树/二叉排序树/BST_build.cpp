#include "function.h"

//�����������Ľ���
void Build_BST_1(BiTree& T,KeyType arr[],int len) {
	for (int i = 0; i < len; i++) {
		BST_insert_1(T, arr[i]);
	}
}

//�����������Ľ���
bool BST_insert_1(BiTree& T, KeyType k) {
	BiTree TreeNew = (BSTNode*)calloc(1, sizeof(BSTNode));  //�½������ռ�
	if(TreeNew)
		TreeNew->key = k;   //��ֵ��������
	if (NULL == T) {
		T = TreeNew;      //�½����Ϊ���ĸ�
		return true;
	}
	BiTree p = T, parent=NULL; //p����������
	while (p) {       //�ҵ�Ҷ�ڵ�
		parent = p;   //��p�ĸ����
		if (k > p->key) {
			p = p->rchild;
		}
		else if (k < p->key) {
			p = p->lchild;
		}
		else {
			return false;  //��ȵ�Ԫ�ش���ʱ������
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

//�����������Ľ������ݹ飩
void Build_BST_2(BiTree& T, KeyType arr[], int len) {
	for (int i = 0; i < len; i++) {
		BST_insert_2(T, arr[i]);
	}
}

//�����������Ľ������ݹ飩
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

//�������
void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->lchild);
		printf("%d ", T->key);
		InOrder(T->rchild);
	}
}