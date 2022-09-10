#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // function 1 
    int subsetSum(int n, int arr[], int sum){
        int t[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0)
                    t[i][j] = 0;
                if(j==0)
                    t[i][j] = 1;
                    
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1] <= j)
                    t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][sum];
    }

    // function 2
    int equalPartition(int n, int arr[]){
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = sum + arr[i];
        }
        if(sum%2!=0)
            return 0;
        else{
            sum = sum/2;
            return subsetSum(n, arr, sum);  // fn. from previous problem -> since it gets reduced to prev problem!
        }
    }
};

int main()
{
    int n;
    cin>> n;

    int arr[n];
    for(int i= 0; i< n; i++)
        cin>> arr[i];

    Solution obj;
    obj.equalPartition(n, arr);
    return 0;
}