#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct Node{
    struct Node* Next;
    ElementType Element;
};

typedef struct Node* Position;
typedef Position List;

void makeNullList(List *Header){
    (*Header) = (struct Node*)malloc(sizeof(struct Node*));
    (*Header)->Next = NULL;
}

int emptyList(List L){
    return (L->Next == NULL);
}

void insertList(ElementType X, Position P, List *L){
    Position T;
    T = (struct Node*)malloc(sizeof(struct Node*));
    T->Element = X;
    T->Next = P->Next;
    P->Next = T;
}

void deleteList(Position P, List *L){
    Position T;
    if(P->Next != NULL){
        T->Next = P->Next;
        P->Next = P->Next->Next;
        free(T);
    }
    else
        printf("\nLoi! Danh sach rong khong the xoa");
}

Position Locate(ElementType X, List L){
    Position P;
    int found = 0;
    while((P->Next != NULL) && (found == 0)){
        if(P->Next->Element == X)
            found = 1;
        else
            P = P->Next;
    }
    return P;
}

ElementType Retrieve(Position P, List L){
    if(P->Next != NULL)
       return P->Next->Element;
}

Position First(List L){
    return L;
}

Position endList(List L){
    Position P;
    P = First(L);
    while(P->Next != NULL){
        P = P->Next;
    }
    return P;
}

void readList(List *L){
    int i, n;
    ElementType X;
    printf("So phan tu trong danh sach: "); scanf("%d", &n);
    for(i = 1; i <= n; i++){
        printf("Phan tu thu %d: ", i); scanf("%d", &X);
        insertList(X, endList(*L), L);
    }
}

void printList(List L){
    Position P;
    P = First(L);
    while(P != endList(L)){
        printf("%d", Retrieve(P, L));
        P = P->Next;
    }
}

void append(int x, List *pL){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->Element = x;
    newNode->Next = NULL;
    if(*pL == NULL)
         *pL = newNode;
    else{
        struct Node *lastNode = *pL;
        while(lastNode->Next != NULL){
            lastNode = lastNode->Next;
        }
        lastNode->Next = newNode;
    }
}
