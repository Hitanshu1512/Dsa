#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    bool ispalindrome(string& str,int i,int j){
        if(i==j)
            return true;
        if(i>j)
            return true;
        while(i<j){
            if(str[i] != str[j])
                return false;
            i++;
            j--;
                
        }
        return true;
    }
    int palpar(string& str,int i,int j){
        if(i>=j)
            return 0;
        else if(dp[i][j] != -1)
            return dp[i][j];
        else if(ispalindrome(str,i,j)){
            dp[i][j] = 0;
            return 0;
        }

        int mn = INT_MAX;    
        for(int k{i} ; k<=j-1 ; k++){
            int left{0};
            int right{0};
            if(ispalindrome(str,i,k)){
                right = palpar(str,k+1,j);
            }
            else{
                dp[i][k] = 0;
                continue;
            }
            
            int temp = right+1;
            mn = min(mn,temp);
        }
        return dp[i][j] = mn;
    }
    int palindromicPartition(string str) {
        int n = str.length();
        dp.resize(n+1,vector<int>(n+1,-1));
        return palpar(str,0,n-1);
    }
  
};

// driver code
int main()
{
    Solution obj;
    string str;
    cin>> str;

    cout<< obj.palindromicPartition(str)<< endl;
    return 0;
}