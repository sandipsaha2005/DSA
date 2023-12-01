#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;

void display(node *head){
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    node *p = head;
    printf("The Elements are:");
    
    do {
        printf(" %d ", p->data);
        p = p->next;
    } while (p != head);

    printf("\n");
}

node *insertAtStart(node *head,int data){
    node *NewNode=(node*)malloc(sizeof(node));
    NewNode->data=data;
    node *p=head;
    do{
        p=p->next;
    }while (p->next!=head);
   
    NewNode->next=head;
    p->next=NewNode;
    return NewNode;   
}
node *insertAtIndex(node *head,int data,int index){
    node *NewNode=(node*)malloc(sizeof(node));
    NewNode->data=data;
    node *p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    NewNode->next=p->next;
    p->next=NewNode;
    return head;
}
node *insertAtEnd(node *head,int data){
    node *NewNode=(node*)malloc(sizeof(node));
    NewNode->data=data;
    node *p=head;
    do{
        p=p->next;
    }while(p->next!=head);
    NewNode->next=p->next;
    p->next=NewNode;
    return head;
}

int main(){
    node *head=(node*)malloc(sizeof(node));
    node *first=(node*)malloc(sizeof(node));
    node *second=(node*)malloc(sizeof(node));
    node *third=(node*)malloc(sizeof(node));
    node *fourth=(node*)malloc(sizeof(node));
    node *fifth=(node*)malloc(sizeof(node));
    node *sixth=(node*)malloc(sizeof(node));

    head->data=32;
    head->next=first;

    first->data=31;
    first->next=second;

    second->data=98;
    second->next=third;

    third->data=76;
    third->next=fourth;

    fourth->data=87; 
    fourth->next=fifth;

    fifth->data=44;
    fifth->next=sixth;

    sixth->data=59;
    sixth->next=head;

    printf("Before insertino\n");
    display(head);
    // head=insertAtStart(head,54);
    // head=insertAtIndex(head,65,3);
    head=insertAtEnd(head,97);
    printf("After insertino\n");
    display(head);
    // display(head);
    return 0;
}