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

Node* push_back(){
    int data;
    cin>> data;

    Node* head = NULL; // to avoid seg.fault
    Node* tail = NULL; // to avoid seg. fault

    while(data != -1){
        Node* n = new Node(data);

        if(head == NULL){ 
            head = n;
            tail = n;
        }
        else{
            tail->next = n; // Connecting the nodes! Insert data at the  end of list
            tail = n; // update the tail
            // or, tail = tail->next;
        }
        cin>> data;
    }
    return head;
}

Node* deleteNode(Node* head, int pos){
    
    if(pos<0)
        return head;
    if(pos == 0 && head != NULL) // if head == NULL, then it will point NULL->next which produces runtime error! 
        return head->next;  // Memory Leak
    
    Node* temp = head;
    int count = 1   ;
    while(count <= pos-1 && temp != NULL){
        temp = temp->next;
        count++;
    }
    if(temp && temp->next) // means, they should exist, i.e. they must not be equal to null!
    {
        temp->next = temp->next->next;
        return head;
    }
    return head;
}

int main()
{
    cout<< "Enter numbers in the List: ";
    Node *p = push_back();
    cout<< "linked-list: ";
    print(p);
    cout<< "Delete node: ";
    int d;
    cin>> d;
    deleteNode(p, d);
    cout<< "Linked-list after deletion: ";
    print(p);
    return 0;
}