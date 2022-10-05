// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
#include <bits/stdc++.h>
using namespace std;

/* Linked List Node structure:*/

struct Node
{
    int data;
    struct Node *next;
};

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        Node *curr = head;
        Node *prev = NULL;
        
        while(curr){
            Node *n = curr->next;   // store the next of current first
            curr->next = prev;      // now make the connection
            
            // Now move the pointers to new location i.e. backwards
            prev = curr;
            curr = n;
        }
        // return prev to get a reversed list
        return prev;
    }
};