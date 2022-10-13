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
    //Function to find the height of a binary tree.
    int height(struct Node* node)
    {
        //if node is null, we return 0.
        if (node==NULL)
            return 0;

        //else we call the recursive function, height for left and right 
        //subtree and choose their maximum. we also add 1 to the result
        //which indicates height of root of the tree.
        else
            return 1 + max(height(node->left), height(node->right));
    }    
};