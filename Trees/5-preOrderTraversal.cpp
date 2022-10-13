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
        void preOrder(Node *root){
            // base condition
            if(root == NULL)
                return;

            // Root - Left - Right
            cout<< root->data<< " ";
            preOrder(root->left);
            preOrder(root->right);
        }
};