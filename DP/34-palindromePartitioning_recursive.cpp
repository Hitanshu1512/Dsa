#include <bits/stdc++.h>
using namespace std;

class Solution{
// int t[][];
public:

    bool isPalindrome(string str, int i, int j)
    {
        while(i < j){
            if(str[i] != str[j]){
                return false;
                i++;
                j--;
            }
        }
        return true;
    }

    int solve(string str, int i, int j)
    {
        int ans = INT_MAX;

        // base cond.
        if(i >= j || isPalindrome(str, i, j) == true){
            return 0;
        }

        // k loop scheme
        for(int k= i; k<= j-1; k++){
            int temp_ans = 1 + solve(str ,i, k) + solve(str, k+1, j) ;
            ans = min(ans, temp_ans);
        }
        return ans;
    }

    int palindromicPartition(string str)
    {
        // code here
        int n = str.length();
        int i= 0, j= n-1;
        return solve(str, i, j);
    }
};

// driver code
int main()
{
    Solution obj;
    string str;
    cin>> str;

    cout<< obj.palindromicPartition(str)<< endl;
    return 0;
}