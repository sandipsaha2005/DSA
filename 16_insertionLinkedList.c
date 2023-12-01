#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void linkedListTraverse(struct node *elem){
    while(elem!=NULL){
        printf("Element : %d \n",elem->data);
        elem=elem->next;
    }
}

// function to insert at the begining of a singly linked list;

struct node * insertionLinkedList(struct node *elem, int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=elem;
    return ptr;
}

// function to insert at a specific index of a singly linked list;

struct node *insertionLinkedListIndex(struct node *elem,int data,int index){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=elem;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return elem;
}

// function ot insert at the end of a singly linked list;
struct node *insertionLinkedListAtEnd(struct node *head,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *p=head;
    // int i=0;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

struct node *insertionAfterIndex(struct node *head,struct node *index,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;

    ptr->next=index->next;
    index->next=ptr;
    return head;


}

int main(){
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *sec=(struct node*)malloc(sizeof(struct node));
    struct node *thi=(struct node*)malloc(sizeof(struct node));
    struct node *fou=(struct node*)malloc(sizeof(struct node));
    struct node *fif=(struct node*)malloc(sizeof(struct node));
    struct node *six=(struct node*)malloc(sizeof(struct node));  // not in use
    struct node *sev=(struct node*)malloc(sizeof(struct node));

    head->data=21;
    head->next=sec;

    sec->data=32;
    sec->next=thi;

    thi->data=43;
    thi->next=fou;

    fou->data=44;
    fou->next=fif;  

    fif->data=11;
    fif->next=sev;

    sev->data=19;
    sev->next=NULL;

    linkedListTraverse(head);
    // head=insertionLinkedList(head ,49);
    // head=insertionLinkedListIndex(head ,49,2);
    // printf("After insertion at the begining\n \n");
    printf("\n");
    // head=insertionLinkedListAtEnd(head ,43);


    head=insertionAfterIndex(head ,fif,93);

    linkedListTraverse(head);
    printf("After insertion\n \n");
    return 0;
}