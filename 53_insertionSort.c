#include<stdio.h>
#include<stdlib.h>
// void insertionSort(int *arr, int len) {
//     for (int i = 1; i < len; i++) {
//         int key = arr[i];
//         int j = i - 1;


//         while (j >= 0 && arr[j] > key) {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }
// }

void insertionSort(int *arr,int len){
    for(int i=0;i<len;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void bubbleSort(int *arr,int len){
    int temp;
    for(int i=0;i<len;i++){
        for(int j=0;j<len-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void display(int *arr,int len){
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
        int a[]={15, 12, 8, 20, 15, 10, 25, 18, 30, 22,
        35, 28, 40, 33, 45, 38, 50, 42, 55, 48,};
        // int a[]={2,6,8,3,5};
        int len=sizeof(a)/sizeof(int);
        insertionSort(a,len);
        display(a,len);
        return 0;
}
