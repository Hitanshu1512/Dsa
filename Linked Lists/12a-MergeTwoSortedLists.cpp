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
    // code here
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    Node *finalHead = NULL;
    if (head1->data < head2->data)
    {
        finalHead = head1;
        head1 = head1->next;
    }
    else
    {
        finalHead = head2;
        head2 = head2->next;
    }

    Node *p = finalHead;

    while (head1 and head2)
    {
        if (head1->data < head2->data)
        {
            p->next = head1;
            head1 = head1->next;
        }
        else
        {
            p->next = head2;
            head2 = head2->next;
        }
        p = p->next;
    }
    if (head1)
    {
        p->next = head1;
    }
    else
    {
        p->next = head2;
    }
    return finalHead;
}