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

int countDigits(int n){
    if(n==0){
        return 0;
    }
    int dig = n%10;
    int count = countDigits(n/10) + 1;
    return count;

}

bool isSorted(int* arr, int n){
    if(n==0 || n==1){
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    }else{
        bool ans = isSorted(arr+1, n-1);
        return ans;
    }
}

int sumOfArray(int* arr, int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return n;
    }

}

int reverseNumber(int n){
    if(n==0){
        return 0;
    }
    int dig = n%10;
    int rev = reverseNumber(n/10) + (dig*10);

    return rev;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = sumOfArray(arr, n);

    cout<<ans<<endl;

}