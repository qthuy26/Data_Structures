#include <stdio.h>
#define Maxsize 10

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
}

// Ham in hang doi
void printQueue(Queue Q){
    int i = Q.front;
    while(1){
        printf("%d ", Q.data[i]);
        if(i+1 == Q.rear)
            break;
        i = (i+1)%Maxsize;
    }
    printf("\n");
}

int main(){
    Queue Q;
    makenullQueue(&Q);
    enQueue(4, &Q);
    enQueue(6, &Q);
    enQueue(7, &Q);
    enQueue(1, &Q);
    enQueue(2, &Q);
    enQueue(5, &Q);
    enQueue(5, &Q);
    enQueue(6, &Q);
    enQueue(6, &Q);
    printQueue(Q);
    int a;
    deQueue(&Q, &a);
    deQueue(&Q, &a);
    printQueue(Q);
    enQueue(9, &Q);
    enQueue(3, &Q);
    printQueue(Q);
    return 0;
}