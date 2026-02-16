#include <iostream>
using namespace std;

int main(){
    int n;
    int x;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>x;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
    
}