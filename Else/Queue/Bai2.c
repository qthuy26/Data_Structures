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

// Ham dem so phan tu
int count(Queue Q){
    int i = Q.front, count = 0;
    if(emptyQueue(Q))
        return 0;
    while(1){
        count++;
        if(i+1 == Q.rear)
            break;
        i = (i+1)%Maxsize;
    }
    return count;
}

int main(){
    Queue Q;
    makenullQueue(&Q);
    int i, n;
    scanf("%d\n", &n);
    for(i = 0; i < n; i++){
        char hd;
        scanf("%c", &hd);
        if(hd == 'E'){
            int x;
            scanf("%d", &x);
            enQueue(x, &Q);
            printf("%d\n", count(Q));
        }
        else{
            int top;
            deQueue(&Q, &top);
            printf("%d %d\n", top, count(Q));
        }
        scanf("\n");
    }
    return 0;
}