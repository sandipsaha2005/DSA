#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int size;
    int f;
    int r;
    int *arr;
}queue;

int isFull(queue *q){
    if(q->r==q->size-1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(queue *q){
    if(q->r==q->f){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(queue *q,int val){
    if(isFull(q)){
        printf("The queue is overflown !");
    }else{
        q->r++;
        q->arr[q->r]=val;
        // printf("Enqueued ! \n");
    }
}

int dequeue(queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("the queue is underflown !");
    }else{
        q->f++;
        a = q->arr[q->f];
    }
    // printf("\n");
    // free()
    return a;
}

// void display(queue *q)
// {
//     if (isEmpty(q))
//     {
//         printf("queue is empty\n");
//         return;
//     }
//     for (int i = q->f+1; i <= q->r; i++)
//     {
//         printf("%d ", q->arr[i]);
//     }
//     printf("\n");
// }

void display(queue *q){
    if(isEmpty(q)){
        printf("the queue is empty !");
        return;
    }else{
        for(int i=q->f+1; i<=q->r;i++){
            printf(" %d ",q->arr[i]);
        }
        printf("\n");
        return;
    }
    
}
// void display(queue *q){

// }

int main(){
    queue q;
    q.size=10;
    q.f=q.r=-1;
    q.arr=(int *)malloc(q.size *sizeof(int));
    enqueue(&q,45);
    enqueue(&q,15);
    enqueue(&q,65);
    enqueue(&q,25);
    enqueue(&q,85);
    enqueue(&q,22);
    enqueue(&q,20);
    enqueue(&q,20);
    enqueue(&q,20);
    enqueue(&q,20);
    display(&q);
    dequeue(&q);
    
    enqueue(&q,20);
    display(&q);

    // printf("the elements of the queue are -:");
    // printf(" %d",dequeue(&q));
    // printf(" %d",dequeue(&q));
    // printf(" %d",dequeue(&q));
    // printf(" %d",dequeue(&q));
    // printf("The dequed element is %d",dequeue(&q));
    // printf("The dequed element is %d",dequeue(&q));
    // printf("The dequed element is %d",dequeue(&q));
    // printf("The dequed element is %d",dequeue(&q));
    return 0;
}
