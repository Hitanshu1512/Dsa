// https://practice.geeksforgeeks.org/problems/power-set4302/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
#include <bits/stdc++.h>
using namespace std;
// Recursive tree banao, jaha leaf node hai waha answer milega
// baaki nodes pe recursive call hoga!

// base condition ~ Leaf node in recursive tree
void solve(string ip, string op){
    if(ip.length() == 0)
    {
        if(op != "")
            cout<< op<< " ";
        return;
    }
    
    // imitating recursive tree 
    // first ke liye exclude kar rahe hai, second mai include === Decision
    string op1 = op, op2 = op;
    op2.push_back(ip[0]);
    // abb input ko chota karo
    ip.erase(ip.begin()+0); // ip.begin() + jo index delete karna hai woh
    
    // Other nodes
    solve(ip, op1);
    solve(ip, op2);
    return;
}

int main()
{
    string ip, op= "";
    cout<< "Enter Input string: ";
    cin>> ip;
    cout<< "Subsets: ";
    solve(ip, op);
    return 0;
}