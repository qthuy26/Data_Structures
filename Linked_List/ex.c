#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct Node{
    int Elements;
    struct Node *Next;
};


int main(){
    Node *P, *Q, *R, *S, *T, *H;
    P = (Node*)malloc(sizeof(Node));
    Q = (Node*)malloc(sizeof(Node));
    R = (Node*)malloc(sizeof(Node));
    S = (Node*)malloc(sizeof(Node));
    T = (Node*)malloc(sizeof(Node));
    H = (Node*)malloc(sizeof(Node));
    P->Elements = 3;
    P->Next = Q;
    Q->Elements = 4;
    Q->Next = R;
    R->Elements = 2;
    R->Next = S;
    S->Elements = 6;
    S->Next = T;
    T->Elements = 10;
    T->Next = H;
    H->Elements = 9;
    H->Next = NULL;
    printf("%d", P->Next->Next->Next->Next->Next->Next->Elements);
    return 0;
}
