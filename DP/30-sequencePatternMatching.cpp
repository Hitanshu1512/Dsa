#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

// global dp matrix
int t[1001][1001];

bool matchPattern(string X, string Y, int n, int m)
{
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
    int lcs = t[n][m];

    // check if the min. of a string is equal to lcs or not
    if(lcs == X.length())
        return true;
    else
        return false;
}

// driver code
int main()
{
    string X, Y;
    cin>> X>> Y;     // Given sorted strings!

    int n= X.length();
    int m= Y.length();

    if(matchPattern(X, Y, n, m))
        cout<< "true";
    else
        cout<< "false"<< endl;
    return 0;
}