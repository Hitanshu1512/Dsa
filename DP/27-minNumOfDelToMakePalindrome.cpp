// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

// global dp matrix
int t[1001][1001];

int LCS(string X, string Y, int n)
{
    // base cond.
    for(int i= 0; i< n+1; i++)
        t[i][0] = 0;
    for(int j= 0; j< n+1; j++)
        t[0][j] = 0;

    // Now fill remaining part of lookup table
    for(int i= 1; i< n+1; i++){
        for(int j= 1; j< n+1; j++){

            if(X[i-1] == Y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max (t[i][j-1], t[i-1][j]);
        }
    }

    return n - t[n][n];
}

int minDeletions(string str, int n) { 
    //complete the function here 
    string str2 = str;
    reverse(str2.begin(), str2.end());
    return LCS(str, str2, n);
}

// driver code
int main()
{
    string X;
    cin>> X;     // Given sorted strings!

    int n= X.length();

    cout<< minDeletions(X, n)<< endl;
    return 0;
}