#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>&s,int cnt, int size){
    while(cnt == size/2){
        s.pop();
        return;
    }
    int num = s.top();
    s.pop();

    solve(s, cnt+1, size);

    s.push(num);
}

void deleteMiddle(stack<int>&s, int size){
    int cnt = 0;
    solve(s, cnt, size);
}

int main(){

    stack<int> s;
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    int size = s.size();

    deleteMiddle(s, size);

}