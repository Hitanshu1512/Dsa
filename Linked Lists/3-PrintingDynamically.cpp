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
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL"<< endl;
}

int main()
{
// <stackMemory> ---> <heapMemory>
    Node *n1 = new Node(100);
    Node *n2 = new Node(200);
    Node *n3 = new Node(300);
    Node *n4 = new Node(400);
    Node *n5 = new Node(500);
   
    // Connecting nodes
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // declaring head pointer
    Node *head = n1;
    print(head);
    return 0;
}