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
    // Function to return the diameter of a Binary Tree.
    int diameter(Node *root)
    {
        // Your code here
        int diameter = 0;
        height(root, diameter);
        return diameter + 1; // it returns count of edges, +1 to return count of nodes
    }

    int height(Node *root, int &n)
    {
        if (root == NULL)
            return 0;
        else
        {
            int left = height(root->left, n);
            int right = height(root->right, n);
            n = max(n, left + right); // new line
            return 1 + max(left, right);
        }
    }
};
