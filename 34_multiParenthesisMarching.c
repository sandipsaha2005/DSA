#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
        return;
    }else{
        s->top++;
        s->arr[s->top]=data;
    }

}

char pop(stk *s){
    if(isEmpty(s)){
        printf("the stack is underflown");
    }else{
        char poppedItem=s->arr[s->top];
        s->top--;
        return poppedItem;
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
int match(char a, char b){
    if(a=='(' && b==')'){
        return 1;
    }else if(a=='{' && b=='}'){
        return 1;
    }else if(a=='[' && b==']'){
        return 1;
    }
    return 0;
}

int pthm(char *s,int len){
    stk *sp=(stk *)malloc(sizeof(stk));
    sp->size=len;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size * sizeof(char));
    for(int i=0; s[i]!='\0';i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            push(sp,s[i]);
        }else if(s[i]==')' || s[i]==']' || s[i]=='}'){
            if(isEmpty(sp)){
                free(sp->arr);
                free(sp);
                return 0;
            }else{
                char poppedChar=pop(sp);
                // printf("%c ",poppedChar);
                if(match(s[i],poppedChar)){
                    // printf("he he ");
                    printf("%c",s[i]);
                    return 0;
                }
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
    char *stk="[()]{}{[()()]()}";
    int count=0;
    for(int i=0; stk[i]!='\0';i++){
        count++;
    }
    bool a=true;
    bool b=false;
    if(pthm(stk,count)){
        // printf("parenthesis is matched !");
        // printf(true);
        return a;
    }else{
        printf("parenthesis is not matched !");
        // return ;
    }
    
    return 0;


//https://www.calcont.in/Conversion/infix_to_postfix
}