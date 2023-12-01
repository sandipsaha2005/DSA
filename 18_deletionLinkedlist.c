#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} node;

node display(node *head){
    // node *p=head;
    printf("the elements are :");
    while(head!=NULL){
        printf(" %d ",head->data);
        head=head->next;
    }   
}

// delete at the first index of a linked List 
node *deletionInStart(node *head){
    node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

// delete at a given index of a linked list
node *deletionInIndex(node *head,int index){
    node *p=head;
    node *q=head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

// delete at the end of a linekd list
node *deleteAtEnd(node *head){
    node *p=head;
    node *q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

// delete by meeting key value 
node *deleteWithKey(node *head,int key){
    node *p=head;
    node *q=head->next;
    while(q->data!=key && q->next== NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data==key){
        p->next=q->next;
        free(q);
    }else{
        printf(" \nthe value is not there . Deletion couldn't happed");
        
    }
    return head;
}

int main(){
    node *head=(node *)malloc(sizeof(node));
    node *fir=(node *)malloc(sizeof(node));
    node *sec=(node *)malloc(sizeof(node));
    node *thi=(node *)malloc(sizeof(node));
    node *fou=(node *)malloc(sizeof(node));
    node *fif=(node *)malloc(sizeof(node));
    node *six=(node *)malloc(sizeof(node));
    head->data=21;
    head->next=fir;

    fir->data=34;
    fir->next=sec;

    sec->data=32;
    sec->next=thi;

    thi->data=98;
    thi->next=fou;

    fou->data=25;
    fou->next=fif;

    fif->data=87;
    fif->next=six;

    six->data=14;
    six->next=NULL;

    display(head);
    // head=deletionInStart(head);
    // head=deletionInIndex(head,3);
    // head=deleteAtEnd(head);
    head=deleteWithKey(head,100);
    printf("\n");
    display(head);
    return 0;
}