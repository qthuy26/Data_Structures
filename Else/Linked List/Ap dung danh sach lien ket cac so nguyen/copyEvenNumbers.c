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

// Them phan tu vao cuoi danh sach
void append(int x, List *list){
	Position PEnd = *list;
	// Tim nut cuoi danh sach
	while(PEnd->Next != NULL){
		PEnd = PEnd->Next;
	}
	insertList(x, PEnd, list);
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

// Kiem tra mot phan tu co trong danh sach
int member(int x, List list){
	Position P = list;
	int found = 0;
	while(P->Next != NULL && found == 0){
		if(P->Next->Element == x)
			return 1;
		else
			P = P->Next;
	}
	return 0;
}

// Them mot phan tu vao dau danh sach
void addFirst(int x, List *list){
	Position T = (struct Node*)malloc(sizeof(struct Node));
	T->Element = x;
	T->Next = (*list)->Next;
	(*list)->Next = T;
}

// Nhap vao danh sach, nhung phan tu chua ton tai thi them vao
List readSet(){
	List L;
	makenullList(&L);
	int x, i, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &x);
		if(!member(x, L))
			addFirst(x, &L);
	}
	return L;
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

// Chep tat ca so chan trong L1 sang L2
void copyEvenNumbers(List L1, List *L2){
	makenullList(L2);
	Position P = L1->Next;
	while(P != NULL){
		if(P->Element % 2 == 0)
			append(P->Element, L2);
		P = P->Next;
	}
}

int main(){ 	
	List L1;
	makenullList(&L1);
	readList(&L1);
	printList(L1);
	List L2;
	copyEvenNumbers(L1, &L2);
	printList(L2);
	printf("%.3f", getAvg(L2));
	return 0;
}
