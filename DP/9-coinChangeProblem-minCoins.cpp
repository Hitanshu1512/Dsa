#include <bits/stdc++.h>
using namespace std;

class Solution{
    int t[1001][1001];
	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code (Unbounded knapsack)
        
        // Initialization
        for(int j= 0; j< V+1; j++)
            t[0][j] = INT_MAX - 1;
        for(int i= 0; i< M+1; i++)
            t[i][0] = 0;
        
        for(int i= 1; i< M+1; i++){
            for(int j= 1; j< V+1; j++){
                // * replace N with i and sum with j *
                if(coins[i-1] <= j){
                    t[i][j] = min(t[i-1][j] , (1 + t[i][j-coins[i-1]])); // choices : excluded + included
                }
                else{
                    t[i][j] = t[i-1][j]; // excluded
                }
            }
        }
        if(t[M][V] == INT_MAX - 1)
            return -1;
        else
            return t[M][V];
	} 
};

int main()
{
    Solution obj;
    int M,  V;
    cin>> M>> V;
    int coins[M];
    for(int i= 0; i< M; i++)
        cin>> coins[i];
    
    cout<< obj.minCoins(coins, M, V)<< endl;
    return 0;
}