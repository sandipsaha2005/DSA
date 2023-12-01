#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    char *arr;
    int size;
    int top;
}stk;

int isEmpty(stk *s){
    if(s->top==-1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(stk *s){
    if(s->top==s->size -1){
        return 1;
    }else{
        return 0;
    }
}

void push(stk *s,char data){
    if(isFull(s)){
        printf("stack overflown");
    }else{
        s->top++;
        s->arr[s->top]=data;
    }

}

void pop(stk *s){
    if(isEmpty(s)){
        printf("the stack is underflown");
    }else{
        s->top--;
    }
}

// void display(stk *s){
//     for(int i=0; s->arr[i]!='\0';i++){
//         printf(
//             "%c ",s->arr[i]
//         );
//     }
// }

void display(stk *s) {
    for (int i = 0; s->arr[i] != '\0'; i++) {
        printf("%c ", s->arr[i]);
    }
    printf("\n");
}

int pthm(char *s,int len){
    stk *sp=(stk *)malloc(sizeof(stk));
    sp->size=len;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size * sizeof(char));
    for(int i=0; s[i]!='\0';i++){
        if(s[i]=='('){
            push(sp,'(');
        }else if(s[i]==')'){
            if(isEmpty(sp)){
                
                free(sp->arr);
                free(sp);
                return 0;
            }else{
                pop(sp);
                // return 1;
            }
        }
    }
    int result = isEmpty(sp); // Check if the stack is empty after processing

    free(sp->arr);
    free(sp);
    
    return result;
}
int main(){
    char *stk="((())((())))";
    // int len=sizeof( *stk)/sizeof(char);
    int count=0;
    for(int i=0;stk[i]!='\0';i++){
        count++;
    }
    // printf("%d \n",count);
    if(pthm(stk,count)){
        printf("parenthesis is matched !");
    }else{
        printf("parenthesis is not matched !");
    }
    return 0;

}