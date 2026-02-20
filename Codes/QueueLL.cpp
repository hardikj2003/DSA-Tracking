#include <iostream>
using namespace std;

class Node{
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

    void enqueue(int e){
        Node* newNode = new Node(e);

        if (rear == NULL) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void dequeue(){
        if (front == NULL) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = front;
        front = front->next;

        if (front == NULL){
            rear = NULL;
        }
        delete temp;
    }
    int peek() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    Queue q;
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(9);
    q.enqueue(8);
    q.enqueue(7);
    q.dequeue();
    q.dequeue();
    q.display();
}