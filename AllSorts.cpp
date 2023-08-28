#include<iostream>
using namespace std; 
void bubbleSort(int *arr, int n){

    //throw largest in last
    for(int i = 0; i < n; i++){

        for(int j = 0; j < n-1-i; j++){

            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
void selectionSort(int *arr, int n){

    //smallest in first directly getting posn of smallest element in one go

    for(int i = 0; i < n; i++){
        int curr = arr[i];
        int Small_Idx = i;
        for(int j = i+1; j < n; j++){

            if(arr[Small_Idx]>arr[j]){
                Small_Idx = j;
            }

        }
        swap(arr[Small_Idx],arr[i]);
    }
}

void insertionSort(int *arr, int n){

    //solving prev part and choosing then shifting for right posn for curr
    for(int i = 1; i < n; i++){
    int prev = i-1;
    int curr = arr[i];

        while(prev>=0 && curr<arr[prev]){
            arr[prev+1] = arr[prev];
            prev--;
        }

        arr[prev + 1] = curr;

    }
}
void merge(int *arr, int si, int mid, int ei){
    
    int temp[ei-si+1];
    int k = 0;

    int i = si;
    int j = mid+1;

    while(i<=mid && j <= ei){
        if(arr[i]<arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while (j<=ei){
        temp[k++] = arr[j++];
    }

    for(int i = si, k = 0; k < ei-si+1; k++,i++){
        arr[i] = temp[k];
    }
    
}
void mergeSort(int *arr, int si, int ei){
    if(si>=ei){
        return;
    }
    int mid = si + (ei-si)/2;

    mergeSort(arr,si,mid);
    mergeSort(arr,mid+1,ei);

    merge(arr,si,mid,ei);
}

int partition(int *arr, int si, int ei){

    int pvt = arr[si];
 
    int count = 0;
    for(int i = si+1; i <= ei; i++){
        if(arr[i]<=pvt){
            count++;
        }
    }

    int pvtIdx = si + count;
    swap(arr[pvtIdx],arr[si]); //Remember

    int i = si;
    int j = ei;

    while(i<pvtIdx && j>pvtIdx){
        while(arr[i]<=pvt){
            i++;
        }
        while(arr[j]>pvt){
            j--;
        }
        if(i<pvtIdx && j>pvtIdx){
            swap(arr[i++],arr[j--]);
        }
    }
    return pvtIdx;
}

void quickSort(int *arr, int si, int ei){
    if(si>= ei){
        return;
    }
    //arr[0] ki right place me bhej do 
    //p = partition kr ke
    //0 se pvt-1
    //pvt+1 se ei

    int p = partition(arr, si, ei);

    quickSort(arr,0,p-1);
    quickSort(arr,p+1,ei);


    
}

int main(){
    
    int arr[] = {5,-1,9,4,8,14,0};
    int n = 7;

    // bubbleSort(arr,7);

    // selectionSort(arr,7);


    // insertionSort(arr,7);

    // mergeSort(arr,0,6);

    quickSort(arr, 0, 6);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}