#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void linkedListTraverse(struct node *elem){
    while(elem!=NULL){
        printf("the element is : %d \n",elem->data);
        elem=elem->next;
    }
}

int main(){
    struct node *heap;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;
    struct node *sixth;
    struct node *seventh;
    struct node *eight;
    struct node *ninth;

    heap=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));
    fifth=(struct node *)malloc(sizeof(struct node));
    sixth=(struct node *)malloc(sizeof(struct node));
    seventh=(struct node *)malloc(sizeof(struct node));
    eight=(struct node *)malloc(sizeof(struct node));
    ninth=(struct node *)malloc(sizeof(struct node));

    heap->data=21;
    heap->next=second;

    second->data=87;
    second->next=third;

    third->data=98;
    third->next=fourth;

    fourth->data=36;
    fourth->next=fifth;

    fifth->data=14;
    fifth->next=sixth;

    sixth->data=32;
    sixth->next=seventh;

    seventh->data=54;
    seventh->next=eight;

    eight->data=93;
    eight->next=NULL;

    ninth->data=100;
    ninth->next=heap;  // not working

    linkedListTraverse(heap);


    struct node* current = heap;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;

}

