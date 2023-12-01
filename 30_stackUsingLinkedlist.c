#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;

int isEmpty(node *top){
    if(top==NULL){
        return 1;
    }else{
        return 0;
    }
}
void display(node *top){
    node *p=top;
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=NULL);
    // printf("%d",p->data);
    printf("\n");
}

node *push(node *top,int data){
    node *newNode=(node *)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=top;
    return newNode;
}
// int  pop(node **top){
//     if(isEmpty(*top)){
//         printf("The stack is underflown");
//     }else{
//         node *p=*top;
//         *top=(*top)->next;
//         int popeditem=p->data;
//         free(p);
//         return popeditem;
//     }
    
// }
node *pop(node *top){
    if(isEmpty(top)){
        printf("The stack is underflown");
    }else{
        node *p=top;
        top=top->next;
        printf("the oppped itme is :%d \n",p->data);
        free(p);
        return top;
    }
}
int main(){
    node *top=NULL;
    top=push(top,45);
    top=push(top,49);
    top=push(top,25);
    top=push(top,12);
    top=push(top,98);
    top=push(top,25);
    top=push(top,98);
    top=push(top,45);
    top=push(top,85);
    top=push(top,73);
    display(top);

    top=pop(top);
    top=pop(top);
    top=pop(top);
    // int popeditem=pop(&top);
    // printf("the popped itme is :%d \n",popeditem);
    display(top);

}