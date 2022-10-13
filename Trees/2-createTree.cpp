#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    // constructor
    Node(int val){
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

// CREATE TREE
Node *buildTree(Node* root){
    int data;
    cout<<"Enter data: ";
    cin>> data;
    root = new Node(data); // constructor calling => creating the tree Node => |NULL|data|NULL|

    // base condition
    if(data == -1)
        return NULL;
    
    cout<< "Enter left of "<< data<< ":- "<< endl;
    root->left = buildTree(root->left);     // recursively creating left sub tree

    cout<< "Enter right of "<< data<< ":- "<< endl;
    root->right = buildTree(root->right);   // recursively creating right sub tree

    return root;
}

// driver code
int main()
{
    Node *root = NULL;
    root = buildTree(root);

    return 0;
}