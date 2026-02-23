#include <iostream>
using namespace std;

void printNumbersTillN(int n){
    if(n==0){
        return;
    }
    printNumbersTillN(n-1);
    cout<<n<<" ";
}
int factorial(int n){
    if(n==1){
        return 1;
    }

    return n * factorial(n-1);
}

int main(){
    int n;
    cin>>n;
    printNumbersTillN(n);
    cout<<factorial(n)<<endl;
}