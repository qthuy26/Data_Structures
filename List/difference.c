#include <stdio.h>
#define Maxlength 30
typedef struct {
    int Elements[Maxlength];
    int Last;       // So phan tu trong list
}List; 

// Khoi tao danh sach rong
void makenullList(List *L){
    L->Last = 0;
}

// Kiem tra danh sach rong
int emptyList(List L){
	return L.Last == 0;
}

// Kiem tra danh sach day
int fullList(List L){
	return L.Last == Maxlength;
}

// Ham in danh sach
void printList(List L){
	int i;
    for(i = 0; i < L.Last; i++)
    	printf("%d ", L.Elements[i]);
    printf("\n");
}

// Xen mot phan tu vao danh sach
void insertList(int x, int p, List *L){
	if(p < 1 || p > Maxlength || fullList(*L))
		printf("Vi tri khong hop le");
	else{
		int i;
		for(i = L->Last; i >= p; i--)
			L->Elements[i] = L->Elements[i-1];
		L->Elements[p-1] = x;
		L->Last++;
	}
}

// Kiem tra mot phan tu co trong danh sach hay khong
int member(int x, List L){
	int i;
	for(i = 0; i < L.Last; i++)
		if(x == L.Elements[i])
			return 1;
	return 0;
}

// Sap xep danh sach tu be den lon
void sort(List *pL){
	int i, j;
	for(i = 0; i < pL->Last-1; i++)
		for(j = i+1; j < pL->Last; j++)
			if(pL->Elements[i] > pL->Elements[j]){
				int temp = pL->Elements[i];
				pL->Elements[i] = pL->Elements[j];
				pL->Elements[j] = temp;
			}
}	

// Xoa mot phan tu trong danh sach
void deleteList(int p, List *L){
	if(p < 1 || p > L->Last)
		printf("Vi tri khong hop le");
	else{
		int i;
		for(i = p-1; i < L->Last; i++)
			L->Elements[i] = L->Elements[i+1];
		L->Last--;
	}
}

// Doc danh sach
void readList(List *L){
	makenullList(L);
	int x, i, n;
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		scanf("%d", &x);
		insertList(x, i, L);
	}
}

// Chen phan tu vao cuoi danh sach
void insertSet(int x, List *L){
	L->Elements[L->Last] = x;
	L->Last++;
}

// Tinh tap hop hieu cua 2 tap hop bieu dien boi 2 danh sach L1, L2;
void difference(List L1, List L2, List *pL){
	makenullList(pL);
	int i;
	for(i = 0; i < L1.Last; i++)
		if(!member(L1.Elements[i], L2))
			insertSet(L1.Elements[i], pL);
}

int main(){
    List L1,L2,L;
	int i;
	
	makenullList(&L1);
	makenullList(&L2);
	
	for(i=0;i<=5;i++){
	    insertSet(2*i, &L1);
	}
	for(i=4;i<=8;i++){
	    insertSet(2*i, &L2);
	}
	
	for(i=0;i<L1.Last;i++){
	    printf("%d ",L1.Elements[i]);
	}
	printf("\n");
	for(i=0;i<L2.Last;i++){
	    printf("%d ",L2.Elements[i]);
	}
	printf("\n");
	difference(L1,L2,&L);
	for(i=0;i<L.Last;i++){
	    printf("%d ",L.Elements[i]);
	}
    return 0;
}
