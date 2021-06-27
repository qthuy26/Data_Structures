#include <stdio.h>
#define Maxsize 150

typedef struct{
    int data[Maxsize];
    int front, rear;
}Queue;

// Khoi tao hang doi rong
void makenullQueue(Queue *Q){
    Q->front = 0;
    Q->rear = 0;
}

// Kiem tra hang doi rong
int emptyQueue(Queue Q){
    return Q.front == Q.rear;
}

// Kiem tra hang doi day
int fullQueue(Queue Q){
    return (Q.rear+1) % Maxsize == Q.front;     // rear = 9 + 1 = 10 % 10 = 0 == front = 0
}

// Them mot phan tu vao hang doi
void enQueue(int x, Queue *Q){
    if(!fullQueue(*Q)){
        Q->data[Q->rear] = x;
        Q->rear = (Q->rear+1)%Maxsize;
    }   
}

void deQueue(Queue *Q, int *pTop){
    if(!emptyQueue(*Q)){
        *pTop = Q->data[Q->front];
        Q->front = (Q->front+1)%Maxsize;
    }
    else
        *pTop = -1;
}


int main(){
    Queue Q1;
    Queue Q2;
    makenullQueue(&Q1);
    makenullQueue(&Q2);
    int i, n, cnt = 0;
    scanf("%d\n", &n);
    for(i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        enQueue(x, &Q1);
    }
    for(i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        enQueue(x, &Q2);
    }
    while(!emptyQueue(Q2)){
        int a, x;
        deQueue(&Q1, &a);
        if(a != Q2.data[Q2.front]){
            enQueue(a, &Q1);
            cnt++;
        }
        else{
            deQueue(&Q2, &x);
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}