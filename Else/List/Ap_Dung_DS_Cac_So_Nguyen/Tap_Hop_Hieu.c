#include "AListLib.c"

// Ham in danh sach
void printList(List L){
	int i;
    for(i = 0; i < L.Last; i++)
    	printf("%d ", L.Elements[i]);
    printf("\n");
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

void readSet(List *L){
	makenullList(L);
	int n, i, x;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &x);
		if(member(x, *L))
			continue;
		insertSet(x, L);
	}
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
    List L1, L2, pL;
    readSet(&L1);
    readSet(&L2);
    printList(L1);
    printList(L2);
    difference(L1, L2, &pL);
    printList(pL);
    return 0;
}
