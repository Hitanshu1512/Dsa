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

int length(Node* head){         // S = O(1) and T = O(n) -----> Better in space complexity
    Node* temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

int length_recursive(Node *head){               // S = O(n) and T = O(n)
    if(head == NULL)
        return 0;   
    return length_recursive(head-> next)+1;
}

int main()
{
    cout<< "Enter numbers in the List: ";
    Node *p = push_back();
    cout<< "Your linked-list is: ";
    print(p);
    cout<< "Length of your linked-list is: ";
    cout<< length(p)<< endl;
    return 0;
}