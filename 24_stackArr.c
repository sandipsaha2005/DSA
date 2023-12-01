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

int main() {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Stack is created!\n");
    char ins;
    do {
        printf("a to PUSH, p to POP, s to SHOW, e to EXIT: ");
        scanf(" %c", &ins);
        if (ins == 'a' || ins=='A') {
            int len;
            printf("Enter the length: ");
            scanf("%d", &len);
            for (int i = 0; i < len; i++) {
                int elem;
                printf("Enter the value: ");
                scanf("%d", &elem);
                push(s, elem);
            }
        } else if (ins == 'p' || ins=='P') {
            int q;
            printf("Enter how many elements you want to pop: ");
            scanf("%d", &q);
            for (int i = 0; i < q; i++) {
                pop(s);
            }
        } else if (ins == 's' || ins=='S') {
            show(s);
        }
    } while (ins != 'e');

    free(s->arr);
    free(s);

    return 0;
}
