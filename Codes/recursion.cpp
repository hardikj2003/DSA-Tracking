#include <iostream>
#include <string>
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

int sumOfNum(int n){
    if(n==0){
        return 0;
    }
    int digit = n%10;
    int sum = sumOfNum(n/10) + digit;
    return sum;
}

bool isPalindrome(string s, int i, int j){
    if(i>=j){
        return true;
    }

    if(s[i] == s[j]){
        return true;
        isPalindrome(s, i++, j--);
    }
    return false;
}

int main(){
    string s;
    cin>>s;
    cout<<isPalindrome(s, 0, s.length()-1);

}