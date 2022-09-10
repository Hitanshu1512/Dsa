#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n= arr.size();
        bool dp[n+1][sum+1];
        
        // Initialize dp array
        for(int i =0 ; i< n+1; i++)
            dp[i][0] = true;
        for(int j= 1; j< sum+1; j++)
            dp[0][j] = false;
        
        for(int i =1 ; i< n+1; i++){
            for(int j= 1; j< sum+1; j++){
                if(arr[i-1] > sum){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j]; // considering [n-1]th element, so if we are taking it , then we've to remove that from the sum, that's why we are doing: [j-arr[i-1]];
                }
            }
        }
        
        return dp[n][sum];
    }
};

int main()
{
    int n, sum;
    cin>> n;

    vector<int> arr(n);
    for(int i= 0; i< n; i++)
        cin>> arr[i];
    
    cin>> sum;

    Solution obj;
    cout<< obj.isSubsetSum(arr, sum)<< endl;
    return 0;
}