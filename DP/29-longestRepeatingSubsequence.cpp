// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

// solution class
class Solution {

    int t[1001][1001];
    
	public:
        // global dp matrix
        int LongestRepeatingSubsequence(string X)
        {
            int n = X.length();
            // base cond.
            for(int i= 0; i< n+1; i++){
                t[i][0] = 0;
                t[0][i] = 0;
            }
        
            // Now fill remaining part of lookup table
            for(int i= 1; i< n+1; i++){
                for(int j= 1; j< n+1; j++){
        
                    if(X[i-1] == X[j-1] && i != j)  // just a little change here! in lcs code...
                        t[i][j] = 1 + t[i-1][j-1];
                    else
                        t[i][j] = max (t[i][j-1], t[i-1][j]);
                }
            }
        
            return t[n][n];
        }

};

// driver code
int main()
{
    Solution obj;
    string str;
    cin>> str;  
    cout<< obj.LongestRepeatingSubsequence(str)<< endl;
    return 0;
}