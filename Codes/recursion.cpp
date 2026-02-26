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

void printNumbersTillN2(int i, int n){
    if(i>n){
        return;
    }

    cout<<i;
    printNumbersTillN2(i+1, n);
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
        return arr[0];
    }
    int ans = sumOfArray(arr+1, n-1) +arr[0];

    return ans;
}

int reverseNumber(int n){
    if(n==0){
        return 0;
    }
    int dig = n%10;
    int rev = reverseNumber(n/10) + (dig*10);

    return rev;
}

void reverseArray(int* arr, int i, int j, int n){
    if(i>j){
        return;
    }

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    reverseArray(arr, i+1, j-1, n);
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    reverseArray(arr, 0, n-1, n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}