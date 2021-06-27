#include <stdio.h>
#define MaxLength 100

typedef int ElementType;
typedef int Position;
typedef struct{
    ElementType Elements[MaxLength];
    Position Last;
}List;

void makeNullList(List *L){
    L->Last = 0;
}

int emptyList(List L){
    return L.Last == 0;
}

int fullList(List L){
    return L.Last == MaxLength;
}

Position firstList(List L){
    return 1;
}

Position endList(List L){
    return L.Last+1;
}

Position Next(Position P, List L){
    return P+1;
}

Position Previous(Position P, List L){
    return P-1;
}

ElementType Retrieve(Position P, List L){
    return L.Elements[P-1];
}

void insertList(ElementType X, Position P, List *L){
    int i = 0;
    if(L->Last == MaxLength)
        printf("\nDanh sach day !!!");
    else if((P < 1) || (P > L->Last+1))
        printf("\nVi tri khong hop le !!!");
    else{
        for(i = L->Last; i >= P; i--)
            L->Elements[i] = L->Elements[i-1];
        L->Last++;
        L->Elements[P-1] = X;
    }
}

void deleteList(Position P, List *L){
    if((P > L->Last) || (P<1))
        printf("\nVi tri khong hop le !!!");
    else if(emptyList(*L))
        printf("\nDanh sach rong !");
    else{
        Position i;
        for(i = P; i < L->Last; i++)
            L->Elements[i-1] = L->Elements[i];
        L->Last--;
    }
}

void printList(List L){
    Position P;
    P = firstList(L);
    printf("\nBat dau in danh sach ");
    while(P != endList(L)){
        printf("\n%d", Retrieve(P, L));
        P = Next(P, L);
    }
    printf("\nKet thuc in danh sach\n");
}

void readList(List *L){
    int i, N;
    ElementType X;
    makeNullList(L);
    printf("\nNhap vao so phan tu trong danh sach ");
    scanf("%d", &N); fflush(stdin);
    for(i = 1; i <= N; i++){
        printf("\nPhan tu thu %d la ", i);
        scanf("%d", &X); fflush(stdin);
        insertList(X, endList(*L), L);
    }
}

Position Locate(ElementType X, List L){
    Position P;
    int found = 0;
    P = firstList(L);
    while((P != endList(L)) && (found == 0)){
        if(Retrieve(P, L) == X)
            found = 1;
        else
            P = Next(P, L);
    }
    return P;
}

int member(int x, List L){
    Position P = firstList(L);
    int found = 0;
    while((P!=endList(L)) && (found==0)){
        if(Retrieve(P, L) == x){
            found = 1;
            P = 1;
        }
        else{
            P = Next(P, L);
        }
    }
    if(P == endList(L))
        P = 0;
    return P;
}

void insertSet(int x, List *pL){
   int Last = pL->Last;
   pL->Elements[Last] = x;
   pL->Last++;
}
