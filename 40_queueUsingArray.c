#include<stdio.h>
#include<stdlib.h>

typedef struct circularQueue{
    int size;
    int f;
    int r;
    int *arr;
}circularQueue;

int isFull(circularQueue *q){
    if(q->r==q->size-1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(circularQueue *q){
    if(q->r==q->f){
        return 1;
    }else{
        return 0;
    }
}

void encircularQueue(circularQueue *q,int val){
    if(isFull(q)){
        printf("The circularQueue is overflown !");
    }else{
        q->r++;
        q->arr[q->r]=val;
        // printf("EncircularQueued ! \n");
    }
}

int decircularQueue(circularQueue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("the circularQueue is underflown !");
    }else{
        q->f++;
        a = q->arr[q->f];
    }
    // printf("\n");
    // free()
    return a;
}

// void display(circularQueue *q)
// {
//     if (isEmpty(q))
//     {
//         printf("circularQueue is empty\n");
//         return;
//     }
//     for (int i = q->f+1; i <= q->r; i++)
//     {
//         printf("%d ", q->arr[i]);
//     }
//     printf("\n");
// }

void display(circularQueue *q){
    if(isEmpty(q)){
        printf("the circularQueue is empty !");
        return;
    }else{
        for(int i=q->f+1; i<=q->r;i++){
            printf(" %d ",q->arr[i]);
        }
        printf("\n");
        return;
    }
    
}
// void display(circularQueue *q){

// }

int main(){
    circularQueue q;
    q.size=10;
    q.f=q.r=-1;
    q.arr=(int *)malloc(q.size *sizeof(int));
    encircularQueue(&q,45);
    encircularQueue(&q,15);
    encircularQueue(&q,65);
    encircularQueue(&q,25);
    encircularQueue(&q,85);
    encircularQueue(&q,22);
    encircularQueue(&q,20);
    encircularQueue(&q,20);
    encircularQueue(&q,20);
    encircularQueue(&q,20);
    display(&q);
    decircularQueue(&q);
    
    encircularQueue(&q,20);
    display(&q);

    // printf("the elements of the circularQueue are -:");
    // printf(" %d",decircularQueue(&q));
    // printf(" %d",decircularQueue(&q));
    // printf(" %d",decircularQueue(&q));
    // printf(" %d",decircularQueue(&q));
    // printf("The dequed element is %d",decircularQueue(&q));
    // printf("The dequed element is %d",decircularQueue(&q));
    // printf("The dequed element is %d",decircularQueue(&q));
    // printf("The dequed element is %d",decircularQueue(&q));
    return 0;
}