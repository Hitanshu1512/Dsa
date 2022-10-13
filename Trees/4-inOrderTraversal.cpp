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
        void inOrder(Node *root){
            // base con
            if(root == NULL)
                return;

            // Left - Root - Right
            inOrder(root->left);
            cout<< root->data<< " ";
            inOrder(root->right);
        }
};