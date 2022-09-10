// https://www.geeksforgeeks.org/minimum-insertions-to-form-a-palindrome-dp-28/
// Min Deletions = Min Insertions ---> Same as question 27
//  gfg solution:

#include <bits/stdc++.h>
using namespace std;

class Solution{
  int t[1001][1001];
  public:
  

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

int countMin(string str) { 
    //complete the function here
    int n = str.length();
    string str2 = str;
    reverse(str2.begin(), str2.end());
    return LCS(str, str2, n);
    }
};

int main()
{
    string str;
    cin>> str;
    Solution obj;
    cout<< obj.countMin(str)<< endl;
    return 0;
}