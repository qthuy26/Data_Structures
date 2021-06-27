#include <stdio.h>
#include <stdlib.h>

#define B 10

struct Node{
	int Data;
	struct Node *Next;
};

typedef struct Node* Position;
typedef Position Dictionary[B];


// Hash function
int hash(int x){
	return x % B;
}

// Khoi tao bang bam rong
void makeNullSet(Dictionary D){
	int i;
	for(i = 0; i < B; i++)
		D[i] = NULL;
}

// Kiem tra bang bam rong
int emptySet(Dictionary D){
	int i;
	for(i = 0; i < B; i++)
		if(D[i] != NULL)
			return 0;
	return 1;	
}

// Kiem tra su ton tai cua mot phan tu trong bang bam
int member(int x, Dictionary D){
	Position p;
	int Bucket = hash(x);
	p = D[Bucket];
	int found = 0;
	while(p != NULL && !found){
		if(p->Data == x)
			found = 1;
		else
			p = p->Next;
	}
	return found;
}

// Them mot phan tu vao trong bang bam
void insertSet(int x, Dictionary D){
	int Bucket = hash(x);
	Position p;
	if(!member(x, D)){
		p = D[Bucket];
		D[Bucket] = (struct Node*)malloc(sizeof(struct Node));
		D[Bucket]->Data = x;
		D[Bucket]->Next = p;
	}
}

// In bang bam
void print_Dictionary(Dictionary D){
	int i;
	for(i = 0; i < B; i++){
		Position p = D[i];
		printf("D[%d]: ", i);
		while(p != NULL){
			printf("%d ", p->Data);
			p = p->Next;
		}
		printf("\n");
	}
	printf("\n");
}

// Nhap vao mot bang bam
void read_Dictionary(Dictionary D){
	makeNullSet(D);
	int n, i, x;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &x);
		insertSet(x, D);
	}
}

// Xoa mot phan tu trong dictionary
void deleteSet(int x, Dictionary D){
	int Bucket = hash(x);
	Position p, q;
	// Xoa nut tai phan tu dau
	if(D[Bucket]->Data == x){
		q = D[Bucket];
		D[Bucket] = D[Bucket]->Next;
		free(q);
	}
	else{
		int found = 0;
		p = D[Bucket];
		while(p->Next != NULL && !found){
			if(p->Next->Data == x)
				found = 1;
			else
				p = p->Next;
		}
		if(found){
			q = p->Next;
			p->Next = q->Next;
			free(q);
		}
	}
}


int main(){
	Dictionary D;
	read_Dictionary(D);
	print_Dictionary(D);
	deleteSet(10, D);
	print_Dictionary(D);
	return 0;
}

/*
20
12 13 14 15 16 22 21 23 25 24 10 20 30 18 19 39 79 33 35 17
*/
