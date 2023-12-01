#include<stdio.h>

void display(int arr[],int len){
    for(int i=0;i<=len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void bubbleSort(int *arr,int len){
    int temp;
    for(int i=0; i<len-1; i++){
        for(int j=0; j<len-1-i; j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main(){
    int a[]={5, 12, 8, 20, 15, 10, 25, 18, 30, 22,
        35, 28, 40, 33, 45, 38, 50, 42, 55, 48,

        };

    int len=sizeof(a)/sizeof(int);
    display(a,len);
    // bubbleSort(a,len);
    // display(a,len);
    return 0;
}