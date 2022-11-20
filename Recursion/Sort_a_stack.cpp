// https://practice.geeksforgeeks.org/problems/sort-a-stack/1
/* Same as prev question, but for stack ds*/
#include <bits/stdc++.h>
using namespace std;

// Call by reference
void insert(stack<int> &s, int temp)
{
    if (s.empty() || s.top() <= temp)
    {
        s.push(temp);
        return; // very dangerous!! MUST WRITE IT WHEN PERFORMING RECURSION
    }

    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
    return;
}

void sort(stack<int> &s)
{
    // Your code here
    // base->hypo->induction

    if (s.size() == 1)
    {
        return;
    }

    int temp = s.top();
    s.pop();
    sort(s);
    insert(s, temp);
    return;
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(0);
    s.push(5);
    s.push(2);
    sort(s);
    return 0;
}