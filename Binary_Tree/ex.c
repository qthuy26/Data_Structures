#include <stdio.h>
#include <stdlib.h>

typedef struct TNode{
	int key;
	struct TNode *left, *right;
}TNode;

typedef TNode* Tree;

// Khoi tao cay rong
void makenullTree(Tree *pT){
	*pT = NULL;
}

// Kiem tra cay rong
int emptyTree(Tree T){
	return T == NULL;
}

// Xac dinh con ben trai
Tree leftChild(Tree node){
	if(node != NULL)
		return node->left;
	else
		return NULL;
}

// Xac dinh con ben phai
Tree rightChild(Tree node){
	if(node != NULL)
		return node->right;
	else
		return NULL;
}

// Kiem tra co la nut la khong
int isLeaf(Tree node){
	if(node != NULL)
		return node->left == NULL && node->right == NULL;
	return 0;
}

int main(){
	TNode *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8;
	n1 = (struct TNode*)malloc(sizeof(struct TNode));
	n2 = (struct TNode*)malloc(sizeof(struct TNode));
	n3 = (struct TNode*)malloc(sizeof(struct TNode));
	n4 = (struct TNode*)malloc(sizeof(struct TNode));
	n5 = (struct TNode*)malloc(sizeof(struct TNode));
	n6 = (struct TNode*)malloc(sizeof(struct TNode));
	n7 = (struct TNode*)malloc(sizeof(struct TNode));
	n8 = (struct TNode*)malloc(sizeof(struct TNode));
	n1->key = 27;
	n1->left = n2;
	n1->right = n3;
	n2->key = 12;
	n2->left = n4;
	n2->right = n5;
	n3->key = 40;
	n3->left = n6;
	n3->right = n7;
	n4->key = 4;
	n4->left = NULL;
	n4->right = NULL;
	n5->key = 20;
	n5->left = NULL;
	n5->right = NULL;
	n6->key = 34;
	n6->left = n8;
	n6->right = NULL;
	n7->key = 50;
	n7->left = NULL;
	n7->right = NULL;
	n8->key = 30;
	n8->left = NULL;
	n8->right = NULL;
	
	printf("%d", isLeaf(n4));
	
	return 0;
}
