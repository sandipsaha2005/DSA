#include<stdio.h>
void displayarr(int arr[],int size);
void deletion(int arr[],int index,int size);
int main(){
    int arr[]={3,6,7,4,8,9};
    int size=6,index=2;
    // displayarr(arr,size);
    deletion(arr,index,size);
    return 0;
}
void displayarr(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d \t",arr[i]);
    }
}
void deletion(int arr[],int index,int size){
    for(int i=index; i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size-=1;
    printf("\n");
    displayarr(arr,size);
}