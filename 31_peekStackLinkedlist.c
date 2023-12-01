
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

int isEmpty(node* head) {
    if (head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

node* push(node* head, int data) {
    node* newNode = (node*)malloc(sizeof(node));

    newNode->data = data;
    newNode->next = head;
    return newNode;
}

void display(node *top){
    if(isEmpty(top)){
        printf("the stack is empty");
    }
    else{
        node *p=top;
        do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=NULL);
    // printf("%d",p->data);
    printf("\n");
    }
}


node* pop(node* head) {
    if (isEmpty(head)) {
        printf("The stack is underflown.\n");
        return NULL;
    }

    node* p = head;
    int deletedItem = p->data;
    head = p->next;
    free(p);
    printf("%d is popped!\n", deletedItem);
    return head;
}

// int *peek(int pos) {
//     if (isEmpty(head)) {
//         printf("The stack is empty.\n");
//         return -1; // Return a sentinel value to indicate an empty stack
//     }
//     printf("hellow");
//     node *p=head;
//     int count=0;
//     while(p!=NULL){
//         p=p->next;
//         count++;
//     }
//     int i=0;
//     if(pos>count){
//         printf("enter a valid position !");
//     }else{
//         while(i!=pos){
//             p=p->next;
//         }
//         printf("%d \n",p->data);
//     }
//     return head;

// }

int peek(int pos){
    node *p=head;
    for(int i=0;(i<pos-1 && p!=NULL);i++){
        p=p->next;
    }
    if(p!=NULL){
        return p->data;
    }else{
        return -1;
    }

}

int main() {
    node* head = NULL;
    char ins;
    int count=0;
    int topElement;
    do {
        printf("Enter 'a' to push, 'd' to display, 'e' to exit: ");
        scanf(" %c", &ins);

        switch (ins) {
            case 'a': {
                int len;
                printf("How many elements do you want to push: ");
                scanf("%d", &len);

                for (int i = 0; i < len; i++) {
                    int data;
                    printf("Enter the element: ");
                    scanf("%d", &data);
                    head = push(head, data);
                    count++;
                }
                break;
            }
            case 'd':
                display(head);
                break;
            case 'e':
                break;
            case 'p':
                topElement = peek(2);
                printf("%d \n",topElement);
                // printf("%d \n",peek(head,2));
                // if (topElement != -1) {
                //     printf("Top element: %d\n", topElement);
                // }
                break;
            default:
                printf("Invalid option. Try again.\n");

        }

    } while (ins != 'e');
    printf("%d",count);
    
    // Free the memory allocated for the linked list
    while (head != NULL) {
        node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;

}




