#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

// global dp matrix
int t[1001][1001];

int LCS(string X, string Y, int n, int m)
{
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    // base cond.
    if(n == 0 || m == 0)
        return 0;
    
    // check dp matrix
    if(t[n][m] != -1)
        return t[n][m];

    // choice diagram
    if(X[n-1] == Y[m-1])
        return t[n][m] = 1+LCS(X, Y, n-1, m-1);

    else
        return t[n][m] = max(LCS(X, Y, n, m-1), LCS(X, Y, n-1, m));
}

// driver code
int main()
{
    memset(t, -1, sizeof(t));
    string X, Y;
    cin>> X>> Y;

    int n= X.length();
    int m= Y.length();

    cout<< LCS(X, Y, n, m)<< endl;
    return 0;
}


/*
GFG APPROACH:-

We can declare the dp[1001][1001] and a boolean flag, globally, i.e., outside all functions and inside the solution Class.
Now, initially the flag stores true value, and we will use this in the LCS function like:

if(flag==true) 
{
     memset(dp, -1, sizeof(dp));
     flag = false; 
}

This flag = false ensures that memset is only applied once, so that it can set the dp array with -1 value only once, as we did, using the main function, thus we successfully memoize the code in platforms like GFG.
CODE:

int dp[1001][1001];
    bool flag = true;
    public: ................cont.
*/