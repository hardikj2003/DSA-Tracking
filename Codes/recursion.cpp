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

int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
    int sum = fibonacci(n-1) + fibonacci(n-2);
    return sum;
}

int main(){
    int n;
    cin>>n;
    cout<<fibonacci(n)<<endl;

}