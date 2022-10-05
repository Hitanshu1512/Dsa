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

int length(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

Node* insert(Node* head, int x, int pos){
    Node* temp = head;
    int n = length(head), count= 1;

    // corner case
    if(pos < 0)
        return temp;

    else if(pos == 0){
        // push_back(x);
        Node* newNode = new Node(x);
        newNode->next = temp;
        temp = newNode;
        return temp;
    }    
  
    while(count<=pos-1 && head != NULL){
        temp = temp->next ;
        count++;
        }

    if(temp){
        Node* newNode = new Node(x);
        newNode->next = temp->next;
        temp->next = newNode;
        return temp;
        }
    
    return temp;
    
}

int main()
{
    cout<< "Enter numbers in the List: ";
    Node *p = push_back();
    cout<< "Original linked-list is: ";
    print(p);
    cout<< "Enter new element and its position: ";
    int pos = 0, x;
    cin>> x>> pos;
    insert(p, x, pos);
    cout<< "Linked-list after insertion is: ";
    print(p);
    return 0;
}