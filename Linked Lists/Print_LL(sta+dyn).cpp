#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;

	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

void print(Node* head){
	Node*  temp = head;
	while(temp != NULL){
		cout<< temp->data<< " -> ";
		temp= temp->next;
	}
	cout<< "NULL ";
}

int main()
{
	//dyn
	Node* n1 = new Node(10);
	Node* n2 = new Node(20);

	//sta
	Node n3(30);
	Node n4(40);

	Node* head = n1;
	n1->next = n2;
	n2->next = &n3;
	n3.next = &n4;
	n4.next = NULL;

	print(head);
	return 0;
}