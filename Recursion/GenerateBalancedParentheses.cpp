#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void solve(int open, int close, string op, vector<string> &v)
    {
        if(open == 0 and close == 0){
            v.push_back(op);
            return;
        }
        // Open karte jaa re, magar dekh ke
        if(open != 0)
        {
            string op1 = op;
            op1.push_back('(');
            solve(open-1, close, op1, v);
        }
        
        if(close > open)    // matlab ki ek open already use hogaya hai, toh usko close karo
        {
            string op2 = op;
            op2.push_back(')');
            solve(open, close-1, op2, v);
            return;
        }
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here
        vector<string> v;
        int open = n, close = n;
        string op = "";
        solve(open, close, op, v);
        return v;
    }
};