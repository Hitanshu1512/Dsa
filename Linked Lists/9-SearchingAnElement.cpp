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

int iterative_search(Node *head, int i){
    Node *temp = head;
    // corner case
    if(i<0 && head)
        return -1;    
    while(temp){
        if(temp->data == i)
            return 1;
        temp = temp->next;
    }
    return 0;
}

bool recursive_search(Node *head, int i){
    if (head == NULL)
        return false;
    if(head->data == i)
        return true;
    return(head->next, i);
}

// driver code
int main()
{
    cout<< "Enter numbers in the List: ";
    Node *p = push_back();
    cout<< "linked-list: ";
    print(p);
    cout<< "Check Element in List: ";
    int i;
    cin>> i;
    // bool ans = (recursive_search(p, i) == 1)? true: false;
    cout<< recursive_search(p, i)<< endl;
    return 0;
}