#include<stdio.h>
#include<math.h>
// int linear(int arr[],int size,int element){
//     for(int i=0;i<size;i++){
//         if(arr[i]==element){
//             return i;
//         }
        
//     }
//     return -1;
// }
// int array(int arr[]){
//     int noOfEl;
//     printf("how manay element do you want to enter :");
//     scanf("%d",&noOfEl);
//     for(int i=0;i<noOfEl;i++){
//         printf("enter the element :");
//         scanf("%d",&arr[i]);
//     }
//     return noOfEl;
// }
// void displayArray(int arr[],int size){
//     for(int i=0;i<size;i++){
//         printf("%d\t",arr[i]);
//     }
//     printf("\n");
// }

// int main(){
//     int arr[100];
//     // array(arr);
//     int noOfelement=array(arr);
//     int size=sizeof(arr)/sizeof(arr[0]);
//     displayArray(arr,noOfelement);
//     int searching;
//     printf("enter the element you are searching for :");
//     scanf("%d",&searching);
//     int result=linear(arr,noOfelement,searching);
//     if(result!=-1){
//         printf("%d is present in the index of %d ",searching,result);
//     }else{
//         printf("the element is not found !");
//     }
//     return 0;
// }


int binarySearch(int arr[],int noO,int element){
    int low,mid,high;
    low=0;
    high=noO-1;
    while(low<=high){
          mid=(low+high)/2;
        if(arr[mid]==element){
            return mid;
        }
        if(arr[mid]<element){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
      
    return -1;
}
int array(int arr[]){
    int noOfEl;
    printf("Enter how many element do you want to eneter :");
    scanf("%d",&noOfEl);
    printf("Please enter all the data in sorted format .\n");
    
    for(int i=0;i<noOfEl;i++){
        printf("Enter the element :");
        scanf("%d",&arr[i]);
    }
    return noOfEl;
}
void displayArray(int arr[],int noO){
    for(int i=0;i<noO;i++){
        printf("%d \t",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[100];;
    int noOfElement=array(arr);
    int searching;
    displayArray(arr,noOfElement);
    printf("Enter the number you are searching for :");
    scanf("%d",&searching);
    int result=binarySearch(arr,noOfElement,searching);
    if(result!=-1){
        printf("The element is present in the index of %d in the array.",result);
    }else{
        printf("The element can not be found in this array ;");
    }
    
    // printf("the elemt is in %d index",binarySearch(arr,6,8));
}