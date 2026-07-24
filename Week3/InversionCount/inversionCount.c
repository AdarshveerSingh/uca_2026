#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(int arr[],int low, int mid, int high){
    
    int temp[high-low+1];
    int i=low;
    int j=mid+1;
    int k=0;

    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=high){
        temp[k++]=arr[j++];
    }
    for(i=0;i<k;i++){
        arr[low+i]=temp[i];
    }
}
void countInversions(int arr[], int low, int mid, int high, long long *count){

    int left=low;
    int right=mid+1;
    for(int i=low;i<=mid;i++){
        while(right<=high && arr[i]>arr[right]){
            right++;
        }
        *count+=right-(mid+1);
    }
}

void mergeSort(int arr[], int low, int high, long long *count){

    if(low>=high){
        return;
    }

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid, count);
    mergeSort(arr, mid + 1, high, count);

    countInversions(arr, low, mid, high, count);

    merge(arr, low, mid, high);
}
int main(){

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long count = 0;

    mergeSort(arr, 0, n - 1, &count);

    printf("%lld\n", count);

    return 0;
    }