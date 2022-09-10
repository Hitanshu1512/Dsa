#include <bits/stdc++.h>
using namespace std;

int dp[101][1001]; // constraints


int knapsack (int val[], int weight[], int n, int w)
{
    if (n == 0 || w == 0){
        return 0;
    }

    if(dp[n][w] != -1){
        return dp[n][w];
    }

    else if(weight[n-1] > w){
       return dp[n][w] = knapsack(val, weight, n-1, w);
    }

    else if(weight[n-1] <= w){
        return dp[n][w] = max(val[n-1]+knapsack(val, weight, n-1, w-weight[n-1]), knapsack(val, weight, n-1, w));       
    }

    return dp[n][w];

}

// driver code
int main()
{
    memset(dp, -1, sizeof(dp));
    int w, n;
    cin>> w>> n;
    int val[n], weight[n];

    for(int i= 0; i< n; i++)
        cin>> val[i]; 
    for(int i= 0; i< n; i++) 
        cin>> weight[i];

    cout<< "Profit: "<< knapsack(val, weight, n, w)<< endl;
    return 0;
}