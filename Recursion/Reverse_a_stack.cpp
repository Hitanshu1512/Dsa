#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Double I B H !!
    void insert(stack<int> &st, int ele)
    {
        if(st.size() == 0){
            st.push(ele);
            return;
        }
        
        int val = st.top();
        st.pop();
        insert(st, ele);
        st.push(val);
        return;
    }
    
    void Reverse(stack<int> &st){
        
        if(st.size() == 1)
            return;
        
        int ele = st.top();
        st.pop();
        Reverse(st);
        insert(st, ele);
        return;
    }
};