
#include<iostream>
using namespace std;


void merge(int * arr,int start,int mid, int end)
{
    int size = end - start + 1;

    int temp[size];

    int i = start, k = 0, j = mid+1;

    while (i<= mid && j <= end){
        if (arr[i] > arr[j]){
            temp[k++] = arr[j++];
        } else {
             temp[k++] = arr[i++];
        }
    }


    while (i<=mid){
        temp[k++] = arr[i++];
    }

    while(j<=end){
         temp[k++] = arr[j++];
    }
    for (i = 0 ; i < size ; i++){
        arr[i] = temp[i];
        delete(temp);
    }
}

void mergeSort(int * arr, int start,int end){

    while (start < end) {

    int mid = (start + end )/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
    }

   

}

int main(){

    int arr[] = {1,2,3,4,56,77};
    
    int size = sizeof(arr)/sizeof(int);
      mergeSort(arr,0,size - 1);
        return 0;
}