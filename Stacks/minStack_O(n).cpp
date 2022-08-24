// https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

#include <bits/stdc++.h>
using namespace std;

stack<int> s;   // Original stack
stack<int> ss;  // Supporting stack

void push(int a)
{
    s.push(a);
    if(ss.size() == 0 || a <= ss.top()){
        ss.push(a);
    }
    return;
}

int pop()
{
    if(s.size() == 0){
        return -1;
    }

    int ans = s.top();
    s.pop();

    if(ss.size() > 0 && ss.top() == s.top()){
        ss.pop();
    }

    return ans;
}

int minElement()
{
    if(ss.size() == 0){
        return -1;
    }

    return ss.top();
}

// Driver code
int main()
{
    int a, n;
    cin >> n;

    for(int i= 0; i< n; i++){
        cin>> a;
        push(a);
    }

    // pop();
    cout<< minElement<< endl;

    return 0;
}