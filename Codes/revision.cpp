#include <bits/stdc++.h>
using namespace std;

class Node {
    public: 
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

class Queue{
    public:
    Node* front;
    Node* rear;

    Queue(){
        front = NULL;
        rear = NULL;
    }

    void enqueue(int d){
        Node* newNode = new Node(d);
        if(rear == NULL){
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void dequeue(){
        if(front == NULL){
            cout << "Queue Underflow\n";
            rear = NULL;
            return;
        }
        Node* temp = front;
        front = front->next;

        delete temp;
    }

    int peek(){
        if (front == NULL) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    void display(){
        Node* temp = front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};


int main() {
    Queue q;
    q.enqueue(8);
    q.enqueue(7);
    q.enqueue(6);
    q.enqueue(5);
    q.enqueue(4);
    q.dequeue();
    q.dequeue();
    q.display();

    return 0;
}