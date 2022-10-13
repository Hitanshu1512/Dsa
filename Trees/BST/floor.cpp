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
    int findFloor(Node *root, int input)
    {

        int floor = -1; // hai toh woh root->data return kardo, nahi toh usse just chota wala return kardo
        while (root)
        {
            if (root->data == input)
            {
                floor = root->data;
                return floor;
            }

            else if (input > root->data)
            {
                floor = root->data;
                root = root->right;
            }

            else
            {
                root = root->left;
            }
        }
        return floor;
    }
};