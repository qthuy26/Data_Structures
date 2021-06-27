#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct Node{
    int Element;
    struct Node *Next;
};

typedef struct Node* Position;
typedef Position List;

// Khoi tao danh sach rong
void makenullList(List *list){
	(*list) = (struct Node*)malloc(sizeof(struct Node));
	(*list)->Next = NULL;
}

// Them mot phan tu x vao sau phan tu vi tri P trong danh sach L
void insertList(int x, Position P, List *list){
	Position T;
    T = (struct Node*)malloc(sizeof(struct Node));
    T->Element = x;
    T->Next = P->Next;
    P->Next = T;
}

// In danh sach
void printList(List list){
	Position P = list;
	P = P->Next;
	while(P != NULL){
     	printf("%d ", P->Element);
    	P = P->Next;
	}
	printf("\n");
}

// Doc danh sach
void readList(List *list){
	int i, n, x;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &x);
		Position PEnd = *list;
		// Tim nut cuoi danh sach
		while(PEnd->Next != NULL){
			PEnd = PEnd->Next;
		}
		insertList(x, PEnd, list);
	}
}

// Ham sap xep danh sach tang dan
void sort(List *list){
	Position P, Q;
	P = (*list)->Next;
	while(P != NULL){
		Q = P->Next;
		while(Q != NULL){
			if(P->Element > Q->Element){
				int temp = P->Element;
				P->Element = Q->Element;
				Q->Element = temp;
			}
			Q = Q->Next;
		}
		P = P->Next;
	}
}

int main(){ 	
	List L1;
	makenullList(&L1);
	readList(&L1);
	printList(L1);
	sort(&L1);
	printList(L1);
	return 0;
}
