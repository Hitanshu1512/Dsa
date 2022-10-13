#include <bits/stdc++.h>
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

vector<int> levelOrder(Node* root){
    vector<int> v;      // IT WILL STORE ONLY THE DATA PART OF THE NODE, WHICH WILL BE AOUR ANSWER
    queue<Node *> q;    // REMEMBER, IT WILL STORE THE NODE, MEANS WHOLE NODE ... ADDRESS|DATA|ADDRESS

    // Corner case / base condition
    if(root == NULL)
        return v;   // return 0;

    v.push_back(root->data); // 10
    q.push(root); // 10

    while(q.size() > 0){
        root = q.front(); // tracking out queue while it is not empty and pushing elements in vector, level-wise
        q.pop();

        // if left node exists, print its data and also store that node into the queue 
        // since we are in a loop, it'll again come and visit it and again check for its children nodes
        if(root->left){
            v.push_back(root->left->data);
            q.push(root->left);
        }
        // Similarly, check if right node exists...
        if(root->right){
            v.push_back(root->right->data);
            q.push(root->right);
        }
    }
    return v;
}

// driver code
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    vector<int> ans = levelOrder(root);
    cout<< "In order Traversal: ";
    for(auto it : ans)
        cout<< it<< " ";
    return 0;
}