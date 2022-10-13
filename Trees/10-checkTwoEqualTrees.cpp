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

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        // if one of them is true return true else return false
        if(r1 == NULL || r2 == NULL)
            return (r1 == r2);
        
        return r1->data == r2->data
               && isIdentical(r1->left, r2->left)
               && isIdentical(r1->right, r2->right);
    }
};