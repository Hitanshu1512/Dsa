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
    void solve(Node *root, vector<int> &ans, int level)
    {
        // base case
        if (root == NULL)
            return;
        // we enter new level
        if (level == ans.size())
            ans.push_back(root->data);
        // Only change in the left view code is that...
        // just call right part here first
        solve(root->right, ans, level + 1);
        solve(root->left, ans, level + 1);
    }

    vector<int> leftView(Node *root)
    {
        // Your code here
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};