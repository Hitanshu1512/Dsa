#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to delete middle element of a stack.
    
    void solve(stack<int> &s, int k){
        if(k == 1){
            s.pop();
            return;
        }
        
        int val = s.top();
        s.pop();
        solve(s, k-1);
        s.push(val);
        return;
    }
    
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        if(s.empty())
            return;
        
        int k = (sizeOfStack/2)+1;      
        
        solve(s, k);
        return;
    }
};