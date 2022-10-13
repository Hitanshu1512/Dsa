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

class Solution{
    public:
        void postOrder(Node *root){
            // base condition
            if(root == NULL)
                return;

            // Left - Right - Root
            postOrder(root->left);
            postOrder(root->right);
            cout<< root->data<< " ";
        }
};