#include <iostream>
using namespace std;

void merge(int* arr, int i, int j){
    int mid = i+(j-i)/2;

    int len1 = mid-i +1;
    int len2 = j-mid;

    int* first = new int[len1];
    int* second = new int[len2];

    int mainArrayIndex = i;
    for(int i=0; i<len1; i++){
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++){
        second[i] = arr[mainArrayIndex++];
    }

    int index1 = 0;
    int index2 = 0;

    mainArrayIndex = i;

    while(index1 < len1 && index2 <len2 ){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++]; 
        }else{
            arr[mainArrayIndex++] = second[index2++]; 
        }
    }

    while(index1 < len1){
        arr[mainArrayIndex++] = first[index1++]; 
    }

    while(index2 < len2){
        arr[mainArrayIndex++] = second[index2++]; 
    }


}

void mergeSort(int* arr, int i, int j){
    if(i>=j){
        return;
    } 

    int mid = i+(j-i)/2;

    mergeSort(arr, i, mid);
    mergeSort(arr, mid+1, j);


    merge(arr, i, j);
}

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    mergeSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


}