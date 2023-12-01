#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *stk) {
    if (stk->top == -1) {
        return 1; // Stack is empty
    } else {
        return 0; // Stack is not empty
    }
}

int isFull(struct stack *stt) {
    if (stt->top == stt->size - 1) {
        return 1; // Stack is full
    } else {
        return 0; // Stack is not full
    }
}

void push(struct stack *stk, int value) {
    if (isFull(stk)) {
        printf("The stack is overflowed\n");
    } else {
        stk->top++;
        stk->arr[stk->top] = value;
        printf("%d pushed\n", value);
        
    }
}

void pop(struct stack *stk) {
    if (isEmpty(stk)) {
        printf("The stack is underflown\n");
    } else {
        int poppedItem = stk->arr[stk->top];
        stk->top--;
        printf("The popped item is %d\n", poppedItem);
    }    
}

void show(struct stack *stk) {
    if (isEmpty(stk)) {
        printf("The stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= stk->top; i++) {
            printf("%d ", stk->arr[i]);
        }
        printf("\n");
    }       
}
int peek(struct stack *stk,int i){
    if((stk->top-i+1)<0){
        printf("the position dosen't found :");
        return -1;
    }else{
        return stk->arr[stk->top-i+1];
    }
}
int main() {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Stack is created!\n");
    char ins;
    int elem;
    do {
        printf("a to PUSH, p to POP, s to SHOW, e to EXIT: ");
        scanf(" %c", &ins);
        if (ins == 'a') {
            int len;
            printf("Enter the length: ");
            scanf("%d", &len);
            for (int i = 0; i < len; i++) {
                int elem;
                printf("Enter the value: ");
                scanf("%d", &elem);
                push(s, elem);
            }
        } else if (ins == 'p') {
            int q;
            printf("Enter how many elements you want to pop: ");
            scanf("%d", &q);
            for (int i = 0; i < q; i++) {
                pop(s);
            }
        } else if (ins == 's') {
            show(s);
        }else if(ins =='n'){
            int pos;
            printf("Position that's data you want : \n");
            scanf("%d",&pos);
            if(pos>s->top+1){
                printf("length error ! \n");
            }else{
                elem=peek(s,pos);
                printf("the element is : %d \n",elem);
            }

            // printf("the element is : %d \n",s->top);

            // for(int i=1;i<=s->top+1;i++){
            //     printf("the element in the position of %d is %d \n",i,peek(s,i));
            // }
        }
    } while (ins != 'e');
    printf("stack top : %d\n",s->arr[s->top]);
    printf("stack bottom : %d\n",s->arr[0]);
    free(s->arr);
    free(s);
    
    return 0;
}
