#include<stdio.h>
// void displayarr(int arr[], int max_size);
// int insertion(int arr[],int index,int size,int capacity,int element);

// int main(){
//     int arr[50]={32,54,76,98,100};
//     int size=5,element=34,index=3,capacity=50;
//     displayarr(arr,size);
//     insertion(arr,index,size,capacity,element);
//     // size+=1;
//     // displayarr(arr,size);

//     return 0;
// }
// void displayarr(int arr[], int max_size){
//     printf("the array is : ");
//     for(int i=0; i<max_size;i++){
        
//         printf("%d \t",arr[i]);
//     }
//     printf("\n");
// }
// int insertion(int arr[],int index, int size,int capacity,int element){
//     if(size==capacity){
//         printf("the array is overloaded insertion can not be done !");
//         return -1;
        
//     }else{
//         for(int i=capacity-1;i>=index;i--){
//             arr[i+1]=arr[i];
            
//         }
//     }
//     arr[index]=element;
//     // arr[index+1]=22;
//     size+=1;
//     printf("the element has been inserted successfully : \n");
//     displayarr(arr,size);
//     return 1;
// }

int  insertion(int arr[],int index,int size,int capacity,int element);
void displayarr(int arr[],int size);
int main(){
    int arr[100]={1,4,6,8,9};
    int size=5, element=45,index=3,capacity=100;
    insertion(arr,index,size,capacity,element);
    return 0;
}
int  insertion(int arr[],int index,int size,int capacity,int element){
    if(size==capacity){
        printf("the array is overloaded");
        return -1;
    }
    for(int i=capacity-1;i>=index;i--){
        arr[i+1]=arr[i];  //positioning the elements (khiskano)
        
    }
    arr[index]=element;
    size+=1;
    displayarr(arr,size);
    return 1;
}
void displayarr(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d \t",arr[i]);
    }
    printf("\n");
}