#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // H A S H M A P
    unordered_map<char, int> mp;
    int i= 0, j= 0, mx= -1;
    while(j < s.size())
    {
        // top calculations
        mp[s[j]]++;
        
        if(mp.size() < k)
            j++;
            
        else if(mp.size() == k){
            mx = max(mx, j-i+1);
            j++;    
        }
        
        else if(mp.size() > k){
            mp[s[i]]--;
            if(mp[s[i]] == 0){
                mp.erase(s[i]);
            }
            i++;
            j++;
        }
    }
    
    return mx;
    // mx == INT_MIN? -1: ()
    }
};

int main()
{
    Solution obj;
    string s;
    cin>> s;
    int k;
    cin>> k;
    cout<< obj.longestKSubstr(s, k)<< endl;
    return 0;
}