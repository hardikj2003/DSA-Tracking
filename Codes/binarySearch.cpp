#include <iostream>
using namespace std;

int binarySearch(int* arr, int n, int val){
    int st=0;
    int e = n-1;

    while(st<=e){
        int mid = st + (e - st) / 2;
        if(arr[mid] == val){
            return mid;
        }else if(arr[mid] > val){
            e = mid-1;
        }else{
            st = mid+1;
        }
    }
    return -1;
}

bool binarySearchRecursion(int* arr, int s, int e, int val){
    if(s>e){
        return false;
    }
    int mid = s+ (e-s)/2;

    if(arr[mid] == val){
        return true;
    }

    if(arr[mid] > val){
        return binarySearchRecursion(arr, s, mid-1, val);
    }else{
        return binarySearchRecursion(arr, mid+1, e, val );
    }
}

int main(){
    int n;
    cin>>n;
    int val;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>val;

    // cout<<binarySearch(arr, n, val)<<endl;
    cout<<binarySearchRecursion(arr, 0, n-1, val)<<endl;
}