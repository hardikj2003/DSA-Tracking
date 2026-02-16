#include <iostream>
using namespace std;

class Queue{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    Queue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == size - 1);
    }

    void enqueue(int d){
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;

        rear++;
        arr[rear] = d;
        cout << d << " inserted\n";
    }

    void dequeue(){
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << arr[front] << " removed\n";
        front++;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return;
        }

        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};


int main(){
    Queue q(7);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.dequeue();
    q.dequeue();
    q.display();
    cout<<q.getFront()<<" ";
}