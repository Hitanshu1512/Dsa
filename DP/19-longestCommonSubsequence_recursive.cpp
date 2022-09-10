#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int LCS(string X, string Y, int n, int m)
{
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    // base cond.
    if(n == 0 || m == 0)
        return 0;

    // choice diagram
    if(X[n-1] == Y[m-1])
        return 1+LCS(X, Y, n-1, m-1);

    else
        return max(LCS(X, Y, n, m-1), LCS(X, Y, n-1, m));
}

// driver code
int main()
{
    string X, Y;
    cin>> X>> Y;

    int n= X.length();
    int m= Y.length();

    cout<< LCS(X, Y, n, m)<< endl;
    return 0;
}