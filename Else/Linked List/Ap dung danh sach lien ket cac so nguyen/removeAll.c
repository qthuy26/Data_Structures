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

// Kiem tra danh sach rong
int emptyList(List list){
	return list->Next == NULL;
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

// Xoa mot phan tu sau vi tri P khoi danh sach
void deleteList(Position P, List *list){
	Position temp;
	temp = P->Next;
	P->Next = temp->Next;
	free(temp);
}

// Dinh vi mot phan tu trong danh sach
// Tra ra mot nut truoc nut can tim
Position locate(int x, List list){
	Position P = list;
	int found = 0;
	while(P->Next != NULL && found == 0){
		if(P->Next->Element == x)
			found = 1;
		else
			P = P->Next;
	}
	if(found)
		return P;
	else
		return NULL;
}


// Xoa tat ca cac phan tu co nhan la x
void removeAll(int x, List *list){
	Position P = *list;
	while(P->Next != NULL){
		Position Q = locate(x, P);
		if(Q != NULL)
			deleteList(Q, &P);
		P = Q;
	}
}


int main(){
    List L;
	makenullList(&L);
	readList(&L);
	int x;
	scanf("%d", &x);
	printList(L);	
    removeAll(x, &L);
    printList(L);
    return 0;
}
