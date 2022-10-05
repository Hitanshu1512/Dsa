// https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1
#include <bits/stdc++.h>
using namespace std;

/* Link list Node*/
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here
        Node *slow = head;
        Node *fast = head->next;

        while (fast != NULL and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast)
        { // even case
            return (slow->next)->data;
        }
        else
        { // odd case
            return slow->data;
        }
    }
};