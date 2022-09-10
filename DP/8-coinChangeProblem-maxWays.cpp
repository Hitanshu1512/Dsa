#include <iostream>
using namespace std;

class Solution {
  public:
  long long int t[1001][1001];
    long long int count(int coins[], int N, int sum) {
        // code here.... Unbounded knapsack....
        
        // Initialization
        for(long long int i= 0; i< N+1; i++)
            t[i][0] = 1;
        for(long long int j= 1; j< sum+1; j++)
            t[0][j] = 0;
        
        for(long long int i= 1; i< N+1; i++){
            for(long long int j= 1; j< sum+1; j++){
                // * replace N with i and sum with j *
                if(coins[i-1] <= j){
                    t[i][j] = t[i-1][j] + t[i][j-coins[i-1]]; // choices : excluded + included
                }
                else{
                    t[i][j] = t[i-1][j]; // excluded
                }
            }
        }
        
        return t[N][sum];
    }
};

int main()
{
    Solution obj;
    int n,  sum;
    cin>> n>> sum;
    int arr[n];
    for(int i= 0; i< n; i++)
        cin>> arr[i];
    
    cout<< obj.count(arr, n, sum)<< endl;
    return 0;
}