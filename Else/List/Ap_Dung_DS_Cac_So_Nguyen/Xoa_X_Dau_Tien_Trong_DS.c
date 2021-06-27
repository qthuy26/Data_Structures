#include "AListLib.c"

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

// Ham in danh sach
void printList(List L){
	int i;
    for(i = 0; i < L.Last; i++)
    	printf("%d ", L.Elements[i]);
    printf("\n");
}


int main(){
    List L;
    readList(&L);
    printList(L);
    int x;
    scanf("%d", &x);
    int p = locate(x, L);
    deleteList(p, &L);
    printList(L);
}