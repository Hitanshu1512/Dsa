// same as bounded knapsack. But here, we can take an element many times, if we are considering it -> [i-1] ====>[i].
#include <bits/stdc++.h>
using namespace std;

int knapsack (int val[], int wt[], int n, int w)
{
    int t[n+1][w+1];

    //     1. Initialize matrix
    // for(int i=0; i<w+1; i++) t[0][i] = 0;
    // for(int j=0; j<n+1; j++) t[j][0] = 0;

    // Or, 2. Initialze 0th row and column
    for(int i= 0; i< n+1; i++){
        for(int j=0; j< w+1; j++){
            if(i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for(int i= 1; i< n+1; i++){
        for(int j= 1; j< w+1; j++){
            if(wt[i-1] > j){
                t[i][j] = t[i-1][j];
            }

            else{
                t[i][j] = max((val[i-1]+t[i][j-wt[i-1]]), t[i-1][j]);
            }
        }
    }

    return t[n][w];
}

// driver code
int main()
{
    int w, n;
    cin>> w>> n;
    int val[n], wt[n];

    for(int i= 0; i< n; i++)
        cin>> val[i]; 
    for(int i= 0; i< n; i++) 
        cin>> wt[i];

    cout<< "Profit: "<< knapsack(val, wt, n, w)<< endl;
    return 0;
}