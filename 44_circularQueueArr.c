#include<stdio.h>
#include<stdlib.h>
typedef struct circularQueue{
    int size;
    int f;
    int r;
    int *arr;
}circularQueue;
int isFull(circularQueue *q){
    if ((q->r + 1) % q->size == q->f){

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
        printf("the circularQueue is overflown");
    }else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
        printf("\n%d enqueued \n",val);
    }
}
int decircularQueue(circularQueue *q){
    int a=-1;
    printf("\n");
    if(isEmpty(q)){
        printf("the circularQueue is empty");
    }else{
        q->f=(q->f +1)%q->size;
        a=q->arr[q->f];
        printf("%d dequeued ",a);
        
    }
    printf("\n");
    return a;
}
void display(circularQueue *q) {
    if (isEmpty(q)) {
        printf("The circularQueue is empty.\n");
        return;
    }

    int i = q->f + 1;
    do {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    } while (i != (q->r + 1) % q->size);

    printf("\n");
}
int main(){
    // circularQueue q;
    // q.f=q.r=-1;
    // q.arr=(int *)malloc(q.size * sizeof(int));
    // encircularQueue(&q,43);
    circularQueue *q=(circularQueue *)malloc(sizeof(circularQueue));
    q->f=q->r=0;
    q->size=10;
    q->arr=(int *)malloc(q->size * sizeof(int));
    encircularQueue(q,43);
    encircularQueue(q,44);
    encircularQueue(q,23);
    encircularQueue(q,76);
    encircularQueue(q,87);
    encircularQueue(q,9);
    encircularQueue(q,64);
    encircularQueue(q,114);
    encircularQueue(q,66);

    display(q);
    decircularQueue(q);
    decircularQueue(q); 
    decircularQueue(q);

    encircularQueue(q,690);

    display(q);
    return 1;

}