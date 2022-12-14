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

int print_i(Node* head, int pos){

    if(pos<0)
        return -1;

    int count =1;
    while(count <= pos && head != NULL){
        head= head->next;
        count++;
    }
    if(head) //if(head != NULL)
        return head->data;
    else
        return -1;
}

int main()
{
    cout<< "Enter numbers in the List: ";
    Node *p = push_back();
    cout<< "Original linked-list is: ";
    print(p);
    int i = 0;
    cout<< "Enter Position of node: ";
    cin>> i;
    cout<< "Data at given node is: ";
    cout<< print_i(p, i)<< endl;
    return 0;
}