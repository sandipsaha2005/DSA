#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack{
    int size;
    int top;
    char *arr;
}stack;

int isEmpty(stack *s){
    if(s->top==-1){
        // printf("the stack is underflown !");
        return 1;
    }else{
        return 0;
    }
}

void push(stack *s,char data){
    s->top++;
    s->arr[s->top]=data;
}

char pop(stack *s){
    if(isEmpty(s)){
        // printf("the stack is underflown !");
        return 0;
    }else{
        char poppedItem=s->arr[s->top];
        s->top--;
        return poppedItem;
    }
    
}

char stackTop(stack *s){
    if(isEmpty(s)){
        // printf("The stack is underflown !");
        return 0;
    }else{
        return s->arr[s->top];
    }
}

int prec(char ch){
    if(ch=='*' || ch=='/'){
        return 3;
    }else if(ch=='+' || ch=='-'){
        return 2;
    }else{
        return 0;
    }
}

int isOpt(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' ){
        return 1;
    }else{
        return 0;
    }
}

void display(stack *s){
    int i=0;
    while(s->arr[i]!='\0'){
        printf("%c ",s->arr[i]);
        i++;
    }
    printf("\n");
}


char *inToPost(char *infix){
    stack *s=(stack *)malloc(sizeof(stack));
    s->size=100;
    s->top=-1;
    s->arr=(char *)malloc(s->size * sizeof(char));
    char *postFix=(char *)malloc((strlen(infix)+1) * sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(!isOpt(infix[i])){
            postFix[j]=infix[i];
            i++;
            j++;
        }else{
            if(prec(infix[i])>(prec(stackTop(s)))){
                push(s,infix[i]);
                i++;
            }else{
                postFix[j]=pop(s);
                j++;
            }
        }
    }
    while(!isEmpty(s)){
        postFix[j]=pop(s);
        j++;
    }
    postFix[j]='\0';
    return postFix;

}

int main(){
    char *infix="a*b+c/j*k+w*j-h+h*k/p";
    printf("the exp is %s",inToPost(infix));
    return 0;

}