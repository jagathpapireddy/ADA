#include <stdio.h>
#include<stdlib.h>

void merge(int arr[],int left, int mid, int right){
    int n1= mid-left+1;
    int n2=right-mid;
    int l[n1],r[n2];
    for(int i=0;i<n1;i++){
        l[i]=arr[left+i];
    }
    for(int j=0;j<n2;j++){
        r[j]=arr[right+1+j];
    }
    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(l[i]<=r[j]){
            arr[k]=l[i];
            i++;
        }
        else{
            arr[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=l[i];
        i++;
        k++;
    }
     while(j<n2){
        arr[k]=r[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int left, int right){
    if(left<right){
    int mid = left + (right-left)/2;
    mergesort(arr, left, mid);
    mergesort(arr,mid+1,right);
    
    merge(arr,left,mid,right);
}
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
    mergesort(arr,0,n-1);
    printf("Sorted array:\n");
    printarray(arr, n);

    return 0;
}
