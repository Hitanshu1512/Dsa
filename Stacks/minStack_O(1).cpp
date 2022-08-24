#include <bits/stdc++.h>
using namespace std;

int minElement;
stack<int> s;

void push(int x)
{
    if (s.size() == 0)
    { // if(s.empty())
        s.push(x);
        minElement = x;
    }

    else
    {
        if (x >= minElement)
        {
            s.push(x);
        }
        else if (x < minElement)
        {
            s.push(2 * x - minElement); // flag -> it stores corrupted value in the stack, while the original value gets stored in the minElement .
            minElement = x;
        }
    }
    return;
}

int pop()
{
    if (s.size() == 0)
    {
        return -1;
    }

    else
    {
        if (s.top() >= minElement)
        {
            s.pop();
        }
        else if (s.top() < minElement)
        {
            minElement = minElement * 2 - 1;
            s.pop();
        }
    }
    // return minElement;
}

int top()
{
    if (s.empty())
    {
        return -1;
    }

    else
    {
        if (s.top() >= minElement)
        {
            return s.top();
        }

        else if (s.top() < minElement)
        {
            return minElement;
        }
    }
}

int getMin()
{
    if (s.size() == 0)
    {
        return -1;
    }

    return minElement;
}

// Driver code
int main()
{
    int x, n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        push(x);
    }
    
    // push();
    // pop();
    // getMin();
    cout << getMin() << endl;

    return 0;
}