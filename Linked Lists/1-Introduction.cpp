#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next; //because it is containing the add of the next node

		//constructor
		Node(int data){
			this->data = data;
			next = 	NULL;
		}
};

int main()
{
    // STATICALLY 
	Node n1(1); //Creating node n1
	Node n2(2); //Creating node n2

	n2.next = &n1; //joining the node

    cout<< "Creating first linked list: "<< endl;
	cout<< n1.data<< " -> " << n2.data<< endl; //Printing the data of nodes

    Node* head = &n1; //Creating head of the linked list

    cout<< "Connecting head -> "<< head->data<< " -> !" << endl; 

	// DYNAMICALLY 
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);

	n4 = n3->next;
	cout<< n3->data<< " "<< n3->next;

	// cout<< n3->data << " -> "<< n4->data ;

	
	return 0;
}