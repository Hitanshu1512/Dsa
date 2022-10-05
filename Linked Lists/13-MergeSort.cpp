// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1#include <bits/stdc++.h>
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

class Solution{
  public:
  
    Node* sortedMerge(Node* head1, Node* head2)  
    {  
        // Recursive code here
        if(head1 == NULL)   // base condition
            return head2;
        if(head2 == NULL)
            return head1;
            
        Node *n = NULL;
        if(head1->data < head2->data){
            n = head1;
            n->next = sortedMerge(head1->next, head2);
        }else{
            n = head2;
            n->next = sortedMerge(head1, head2->next);
        }
        return n;
    }
    
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head == NULL || head->next == NULL)
            return head;
            
        // break list into 2
        Node *slow = head;
        Node *fast = head->next;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *n = slow->next; // store it first
        slow->next = NULL;  // break part finishes here
        
        // Now call recursion on the two halves and store the returned sorted lists...
        Node *new1 = mergeSort(head);
        Node *new2 = mergeSort(n);
        
        // Lastly join the two lists and return the head address of the final sorted list
        // Use prev question's function (above)
        sortedMerge(new1, new2);
    }
};