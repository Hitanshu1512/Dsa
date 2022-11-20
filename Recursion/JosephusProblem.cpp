// https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle1840/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(vector<int> &v, int k, int index, int &ans)
    {
        if(v.size() == 1){
            ans = v[0];
            return;
        }
        // Make input smaller ==> by decrementing the vector size
        // Use mod to rotate in vector after (n-1)th pos
        index = (index+k)%v.size();
        v.erase(v.begin()+index);
        // killed that person. Now call on the rem. ones
        // No induction step  is required!
        solve(v, k, index, ans);
        return;
    }
    
    int safePos(int n, int k) {
        // Josephus problem
        k = k-1;    
        // since we are calculating from index 0, so through dry run we do k-- first
        int ans = -1, index = 0;
        vector<int> v;
        for(int i= 0; i< n; i++){
            int x = i+1;
            v.push_back(x);
        }
        solve(v, k, index, ans);
        return ans;
    }
};