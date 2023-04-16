#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef struct BSTNode {
	KeyType key;
	struct BSTNode* lchild, * rchild;
}BSTNode, * BiTree;

void Build_BST_1(BiTree& T, KeyType arr[], int len);
bool BST_insert_1(BiTree& T, KeyType k);
void Build_BST_2(BiTree& T, KeyType arr[], int len);
bool BST_insert_2(BiTree& T, KeyType k);
bool BST_search(BiTree T, KeyType key, BiTree& p, BiTree& pos);

void InOrder(BiTree T);

void BST_del(BiTree& T, KeyType x);