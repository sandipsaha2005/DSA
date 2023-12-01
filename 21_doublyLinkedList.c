#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node *pre;
    int data;
    struct node *next;
}node;
void Display(node *head){
    node *p=head;
    while(p->next!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d",p->data);
    printf("\n");
}

void revDisplay(node *head){
    node *p=head;
    while(p->next!=NULL){
        
        p=p->next;
    }
    // printf("%d",p->data);
    while(p->pre!=NULL){
        printf("%d ",p->data);
        p=p->pre;
    }
    printf("%d",p->data);
    printf("\n");
}

node *insertAtStart(node *head,int data){
    node *NewNode=(node *)malloc(sizeof(node));
    NewNode->data=data;

    node *p=head;
    NewNode->pre=NULL;
    NewNode->next=head;
    return NewNode;
}
node *insertAtIndex(node *head,int data,int index){
    node *NewNode=(node *)malloc(sizeof(node));
    NewNode->data=data;
    int i=0;
    int j=0;
    node *p=head;
    node *q=head;

    while(i!=index-1){
        p=p->next;
        i++;
    }
    while(j!=index){
        q=q->next;
        j++;
    }
    NewNode->next=p->next;
    NewNode->pre=p;
    p->next=NewNode;
    q->pre=NewNode;

    return head;
}
node *insertAtEnd(node *head,int data){
    node *NewNode=(node *)malloc(sizeof(node));
    NewNode->data=data;

    node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    NewNode->next=NULL;
    p->next=NewNode;
    NewNode->pre=p;
    return head;
}
int main(){
    node *head=(node *)malloc(sizeof(node));
    node *a=(node *)malloc(sizeof(node));
    node *b=(node *)malloc(sizeof(node));
    node *c=(node *)malloc(sizeof(node));
    node *d=(node *)malloc(sizeof(node));
    node *e=(node *)malloc(sizeof(node));
    node *f=(node *)malloc(sizeof(node));
    node *g=(node *)malloc(sizeof(node));
    
    head->pre=NULL;
    head->data=32;
    head->next=a;

    a->pre=head;
    a->data=12;
    a->next=b;

    b->pre=a;
    b->data=98;
    b->next=c;

    c->pre=b;
    c->data=54;
    c->next=d;

    d->pre=c;
    d->data=69;
    d->next=e;

    e->pre=d;
    e->data=74;
    e->next=f;

    f->pre=e;
    f->data=25;
    f->next=g;

    g->pre=f;
    g->data=87;
    g->next=NULL;
    Display(head);
    // head=insertAtStart(head,56);
    // head=insertAtIndex(head,56,4);
    head=insertAtEnd(head,56);
    Display(head);
    revDisplay(head);

    return 0;
}