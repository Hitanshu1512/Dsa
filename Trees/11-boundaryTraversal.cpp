#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // constructor
    Node(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    void traverseLeft(Node *root, vector<int> &ans){ // to keep track of answer, pass by ref
        // base case
        if(root == NULL)
            return;
        // if it's a leaf node (base condition)
        if(root->left == NULL && root->right == NULL)
            return;
        // Otherwise keep pushing elements in answer
        ans.push_back(root->data); 
        // Check if left and right of a node are not NULL
        if(root->left)
            traverseLeft(root->left, ans);
        else
            traverseLeft(root->right, ans);
    }
    
    void traverseLeaf(Node *root, vector<int> &ans){
        // base case
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        // Otherwise right ya left jo bhi hai usme move kar jao recusively
        // jaisa in order mai hota hai
        
        traverseLeaf(root->left, ans);  // left
        traverseLeaf(root->right, ans); // right
    }
    
    void traverseRight(Node *root, vector<int> &ans){
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return;
        
        // if right exists, move in right else move in left subtree of same node (root->left)
        if(root->right)
            traverseRight(root->right, ans);
        else
            traverseRight(root->left, ans);
        
        // On returning back in recursion
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root == NULL)
            return ans;
        // Push the root data first
        ans.push_back(root->data);
        // To store left part
        traverseLeft(root->left, ans);
        // traverse Leaf nodes
        // left sub tree
        traverseLeaf(root->left, ans);
        // right sub tree
        traverseLeaf(root->right, ans);
        // To store right part
        traverseRight(root->right, ans);
        
        return ans;
    }
};