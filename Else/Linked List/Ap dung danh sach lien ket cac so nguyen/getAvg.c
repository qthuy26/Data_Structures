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


// Tinh trung binh cong gia tri cac phan tu trong danh sach
float getAvg(List L){
	int sum = 0, cnt = 0;
	Position P = L->Next;
	while(P != NULL){
		sum += P->Element;
		cnt++;
		P = P->Next;
	}
	if(cnt == 0)
		return -10000.0f;
	return (float)sum / cnt; 
}

int main(){
    List L;
	makenullList(&L);
	readList(&L);
	printList(L);
	printf("%.3f", getAvg(L));
}
