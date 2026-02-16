#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&head, int data)
{
    Node *newNode = new Node(data);

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtMiddle(Node *&head, int d, int pos)
{
    Node *newNode = new Node(d);
    if (pos == 1)
    {
        insertAtHead(head, d);
    }
    Node *temp = head;
    int cnt = 1;

    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node *&head, int pos)
{

    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt <= pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void InsertAfterEveryX(Node *&head, int x, int y)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == x)
        {
            Node *newNode = new Node(y);
            newNode->next = temp->next;
            temp->next = newNode;
        }
        temp = temp->next;
    }
}

void deleteAllOccurences(Node* &head, int x)
{
    Node* prev = head;
    Node* curr = head->next;
    while (curr != NULL)
    {
        if (curr->data == x)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void updateDataAtPos(Node *&head, int d, int pos)
{
    if (pos == 1)
    {
        head->data = d;
        return;
    }
    else
    {
        Node *temp = head;
        int cnt = 1;
        while (cnt <= pos)
        {
            temp = temp->next;
            cnt++;
        }

        temp->data = d;
    }
}

int main()
{
    Node *node1 = new Node(5);
    insertAtHead(node1, 10);
    insertAtHead(node1, 5);
    insertAtHead(node1, 12);
    insertAtHead(node1, 5);
    insertAtHead(node1, 5);
    // InsertAfterEveryX(node1, 5, 99);
    deleteAllOccurences(node1, 99);

    print(node1);
}
