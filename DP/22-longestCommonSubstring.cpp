// Substring must me continuous!

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

// global dp matrix
int t[1001][1001];

int LCS(string X, string Y, int n, int m)
{
    // base cond.
    int mx = 0;
    for(int i= 0; i< n+1; i++)
        t[i][0] = 0;
    for(int j= 0; j< m+1; j++)
        t[0][j] = 0;

    // Now fill remaining part of lookup table
    for(int i= 1; i< n+1; i++){
        for(int j= 1; j< m+1; j++){
            
            if(X[i-1] == Y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
                mx = max(mx, t[i][j]);
            }else
                t[i][j] = 0;
        }
        
    }

    return mx;
}

// driver code
int main()
{
    string X, Y;
    cin>> X>> Y;     // Given sorted strings!

    int n= X.length();
    int m= Y.length();

    cout<< LCS(X, Y, n, m)<< endl;
    return 0;
}