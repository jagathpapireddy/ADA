#include <stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    
    while(1){
        while(i<=high && arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i>=j){
            break;
        }
        swap(&arr[i],&arr[j]);
    }
    swap(&arr[low],&arr[j]);
    return j;
}
void quicksort(int arr[], int low, int high){
    if(low<high){
    int p=partition(arr,low,high);
    quicksort(arr,low,p-1);
    quicksort(arr,p+1,high);}
}
void printarray(int arr[],int size){
    for(int i=0; i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[]={10,30,5,15,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("original array:\n");
    printarray(arr,n);
    quicksort(arr,0,n-1);
    printf("Sorted array:\n");
    printarray(arr, n);

    return 0;
}
