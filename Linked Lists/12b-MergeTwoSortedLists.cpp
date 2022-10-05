// https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1
#include <bits/stdc++.h>
using namespace std;

/* Linked List Node structure:*/
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *sortedMerge(Node *head1, Node *head2)
{
    if (head1 == NULL) // base condition
        return head2;
    if (head2 == NULL)
        return head1;

    Node *n = NULL;
    if (head1->data < head2->data)
    {
        n = head1;
        n->next = sortedMerge(head1->next, head2);
    }
    else
    {
        n = head2;
        n->next = sortedMerge(head1, head2->next);
    }
    return n;
}