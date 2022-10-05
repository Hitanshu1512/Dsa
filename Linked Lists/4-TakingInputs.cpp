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

// ---------------------------- USER INPUT 1 AT HEAD ---------------------------------------

Node* push_front(){
    int data;
    cin>> data;

    Node* head = NULL; // assign NULL at the defination to avoid "segmentation Fault"
    Node* tail = NULL; // assign NULL at the defination to avoid "segmentation Fault"

    while(data != -1){
        Node* n = new Node(data);

        if(head == NULL){
            head = n;
            tail = n;
        }
        else{
            n->next = head;
            head = n;
        }
        cin>> data;
    }
    return head;
}

// ---------------------------- USER INPUT 2 AT TAIL ---------------------------------------

Node *push_back(){
    int data;
    cin>> data;

    Node *head = NULL; // to avoid seg.fault
    Node *tail = NULL; // to avoid seg.fault

    while(data != -1){
        Node *n = new Node(data);

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

// driver code
int main()
{
    cout<< "ENTER 2 LINES OF INPUT: "<< endl;

    Node *p = push_back();
    Node *f = push_front();

    cout<< "Original: ";
    print(p);
    cout<< "Reversed: ";
    print(f);
    return 0;
}