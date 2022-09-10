// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

// global dp matrix
int t[1001][1001];

int getMin(string X, string Y, int n, int m)
{
    //////////////////////////// LCS CODE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    // base cond.
    for(int i= 0; i< n+1; i++)
        t[i][0] = 0;
    for(int j= 0; j< m+1; j++)
        t[0][j] = 0;

    // Now fill remaining part of lookup table
    for(int i= 1; i< n+1; i++){
        for(int j= 1; j< m+1; j++){

            if(X[i-1] == Y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max (t[i][j-1], t[i-1][j]);
        }
    }

    // New code i.e. code for min. operations
    int len_of_lcs = t[n][m];
    int del = n - len_of_lcs;
    int ins = m - len_of_lcs;
    return del+ins;
}

/* can be done with two seperate functions also, one for just lcs and another for getting min operations!
int getMin(string X, string Y, int n, int m)
{
    int len_of_lcs = t[n][m];
    int del = n - len_of_lcs;
    int ins = m - len_of_lcs;
    return del+ins;
}*/

// driver code
int main()
{
    string X, Y;
    cin>> X>> Y;     // Given sorted strings!

    int n= X.length();
    int m= Y.length();

    cout<< getMin(X, Y, n, m)<< endl;
    return 0;
}