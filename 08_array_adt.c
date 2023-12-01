#include<stdio.h>
#include<stdlib.h>
typedef struct myclass{
    int max_size;
    int used_size;
    int *ptr; 

}cls;
void creating(cls *array,int tsize,int usize);
void setValue(cls array);
void getValue(cls *array);

int main(){
    cls arr;
    creating(&arr,10,5);
    // printf("%d",arr.used_size);
    printf("Setting values \n");
    setValue(arr);
    printf("Getting ready to show : \n");
    getValue(&arr);

    return 0;
}
void creating(cls *array,int tsize,int usize){
    array->max_size=tsize;
    array->used_size=usize;
    array->ptr=(int*)malloc(tsize *sizeof(int));
}
void setValue(cls array){
    for(int i=0; i<array.used_size; i++){
        printf("enter the index of %d :",i);
        scanf("%d",&array.ptr[i]);
    }
}
void getValue(cls *array){
    for(int i=0; i<array->used_size; i++){
        printf("%d\t",array->ptr[i]);
    }
}