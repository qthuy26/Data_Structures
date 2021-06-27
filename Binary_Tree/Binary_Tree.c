#include <stdio.h>
#include <stdlib.h>

typedef struct TNode{
	int Key;
	struct TNode *Left, *Right;
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
		return node->Left;
	else
		return NULL;
}

// Xac dinh con ben phai
Tree rightChild(Tree node){
	if(node != NULL)
		return node->Right;
	else
		return NULL;
}

// Kiem tra co la nut la khong
int isLeaf(Tree node){
	if(node != NULL)
		return node->Left == NULL && node->Right == NULL;
	return 0;
}

// Them nut
void insertNode(int x, Tree *pT){
	if((*pT) == NULL){
		(*pT) = (struct TNode*)malloc(sizeof(struct TNode));
		(*pT)->Key = x;
		(*pT)->Left = NULL;
		(*pT)->Right = NULL;
	}
	else{
		if((*pT)->Key == x)
			printf("Da ton tai khoa %d\n", x);
		else{
			if(x < (*pT)->Key)
				insertNode(x, &(*pT)->Left);
			else
				insertNode(x, &(*pT)->Right);
		}
	}
}

// Dem so nut cua 1 cay
int nb_nodes(Tree T){
	if(emptyTree(T))
		return 0;
	return 1 + nb_nodes(leftChild(T)) + nb_nodes(rightChild(T));
}

// Duyet tien tu
void preOrder(Tree T){
	printf("%d ", T->Key);
	if(leftChild(T) != NULL)
		preOrder(leftChild(T));
	if(rightChild(T) != NULL)
		preOrder(rightChild(T));
}

// Duyet trung tu
void inOrder(Tree T){
	if(leftChild(T) != NULL)
		inOrder(leftChild(T));
	printf("%d ", T->Key);
	if(rightChild(T) != NULL)
		inOrder(rightChild(T));
}

// Duyet hau tu
void posOrder(Tree T){
	if(leftChild(T) != NULL)
		posOrder(leftChild(T));
	if(rightChild(T) != NULL)
		posOrder(rightChild(T));
	printf("%d ", T->Key);
}

// Dem so nut 1 con
int sonut1con(Tree T){
	if(T == NULL)
		return 0;
	else if(T->Left == NULL && T->Right != NULL)
		return 1 + sonut1con(T->Right);
	else if(T->Left != NULL && T->Right == NULL)
		return 1 + sonut1con(T->Left);
	else return sonut1con(T->Left) + sonut1con(T->Right);
}

int max(int a, int b){
	return a > b ? a : b;
}

// Tinh chieu cao cua cay
int getHeight(Tree T){
	if(emptyTree(T))
		return -1;
	if(T == NULL || (T->Left == NULL && T->Right == NULL))
		return 0;
	return 1 + max(getHeight(T->Left), getHeight(T->Right));
}

// Nhap vao mot cay
void readTree(Tree *pT){
	makenullTree(pT);
	int i, n, x;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &x);
		insertNode(x, pT);
	}
}

// Tim nut co nhan nho nhat
int getNodeMin(Tree *pT){
	int k;
	if((*pT)->Left == NULL){
		k = (*pT)->Key;
		return k;
	}
	else
		return getNodeMin(&(*pT)->Left);
}

// Xoa nut co nhan nho nhat
int deleteMin(Tree *pT){
	int k;
	if((*pT)->Left == NULL){
		k = (*pT)->Key;
		(*pT) = (*pT)->Right;
		return k;
	}
	else
		return deleteMin(&(*pT)->Left);
}

// Tim nut co nhan lon nhat
int getNodeMax(Tree *pT){
	int k;
	if((*pT)->Right == NULL){
		k = (*pT)->Key;
		return k;
//		return (*pT)->Key;
	}
	else
		return getNodeMax(&(*pT)->Right);
}

// Xoa nut co nhan lon nhat
int deleteMax(Tree *pT){
	int k;
	if((*pT)->Right == NULL){
		k = (*pT)->Key;
		(*pT) = (*pT)->Left;
		return k;
	}
	else
		return deleteMax(&(*pT)->Right);
}

// Xoa mot nut co nhan la x
void deleteNode(int x, Tree *pT){
	if((*pT) != NULL){
		if(x < (*pT)->Key)
			deleteNode(x, &(*pT)->Left);
		else if(x > (*pT)->Key)
			deleteNode(x, &(*pT)->Right);
		else{		// x == (*pT)->Key
			if((*pT)->Left == NULL && (*pT)->Right == NULL)
				(*pT) = NULL;
			else if((*pT)->Left != NULL && (*pT)->Right == NULL)
				(*pT) = (*pT)->Left;
			else if((*pT)->Left == NULL && (*pT)->Right != NULL)
				(*pT) = (*pT)->Right;
			else
				(*pT)->Key = deleteMin(&(*pT)->Right);
//				(*pT)->Key = deleteMax(&(*pT)->Left);
		}
	}
}

int main(){
	Tree T;
	readTree(&T);
	preOrder(T);
	printf("\n");
//	inOrder(T);
//	printf("\n");
//	posOrder(T);
//	printf("\n");
//	printf("%d\n", sonut1con(T));
//	printf("%d\n", getHeight(T));
	printf("Min: %d\n", getNodeMin(&T));
	printf("Max: %d\n", getNodeMax(&T));
	int min = deleteMin(&T);
	printf("Test min: %d\n", T->Left->Left->Left->Key);
	int max = deleteMax(&T);
	printf("Test max: %d\n", T->Right->Right->Key);
//	deleteNode(34, &T);
//	printf("Test delete node: %d\n", T->Right->Left->Key);
	
	return 0;
}

/*
11
27 12 40 4 20 34 50 30 6 5 45
*/
