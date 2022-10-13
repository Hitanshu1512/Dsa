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
    int height(Node *root)
    {
        // Base condition
        if (root == NULL)
            return 0;
        // left and right sub tree's height and check if the returned value is -1
        int left_height = height(root->left);
        if (left_height == -1)
            return -1;

        int right_height = height(root->right);
        if (right_height == -1)
            return -1;

        if (abs(left_height - right_height) > 1) // Matlab ki koi ek subtree ki height zyada badi hai doosre subtree se
            return -1;

        return max(left_height, right_height) + 1;
    }

    bool isBalanced(Node *root)
    {
        return (height(root) == -1) ? false : true;
    }
};
