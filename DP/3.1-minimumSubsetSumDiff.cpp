// The absolute  difference should be minimum here : https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // function 1 
    vector<int> isSubsetpossible(int arr[], int n, int sum){
        int t[n+1][sum+1];

        // initialization
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0)
                    t[i][j] = 0;
                if(j==0)
                    t[i][j] = 1; 
            }
        }

        // starting from 2nd row now
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1] <= j)
                    t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        // contains all subset sums possible with n elements. Creating a vector varible to store all the element of the last row 
        vector<int> v;
        for (int j = 0; j <= sum; j++) // from the range we need to exclude the element which is not there in the existing problem 
		{
            if (t[n][j] == true) // In the last row of matrix(i= n), keep true to only those place whose subset sum exist
			    v.push_back(j); // store in the vector 
        }
	    
        return v;
    }

    // function 2
    int subsetDiff(int n, int arr[]){
        
        int range= 0, mn = INT_MAX; // range is actually equal to sum

        for(int i= 0; i< n; i++){
            range+= arr[i];
        }

        vector<int> v = isSubsetpossible(arr, n, range); // subsetSumProblem
        for(int i= 0; i< v.size(); i++){
            mn = min(mn, abs(range-2*v[i]));
        }

        return mn;
    }
};

int main()
{
    int n;
    cin>> n;

    int arr[n];
    for(int i= 0; i< n; i++)
        cin>> arr[i];

    Solution obj;
    cout<< obj.subsetDiff(n, arr)<< endl;
    return 0;
}