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

int main(){
    int n;
    cin>>n;
    int val;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>val;

    cout<<binarySearch(arr, n, val)<<endl;
}