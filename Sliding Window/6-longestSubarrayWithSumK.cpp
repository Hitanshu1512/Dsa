#include <bits/stdc++.h>
using namespace std;

int lenOfLongSubarr(int A[], int N, int K)
{
    // Complete the function
    int i = 0, j = 0, sum = 0, mx = 0;
    while (j < N)
    {
        sum += A[j]; // calculating the sum

        if (sum < K)
            j++;
        else if (sum == K)
        {
            // int size = j-i+1; // we will store maximum size of the window
            mx = max(mx, j - i + 1);
            j++;
        }
        else if (sum > K)
        { // or 'else' only
            while (sum > K)
            {
                sum = sum - A[i];
                i++;
            }
            j++;
        }
    }

    return mx;
}

/*class Solution
{
public:
    int lenOfLongSubarr(int arr[], int n, int k)
    {

        // unordered_map 'um' implemented
        // as hash table
        unordered_map<int, int> um;
        int sum = 0, maxLen = 0;

        // traverse the given array
        for (int i = 0; i < n; i++)
        {

            // accumulate sum
            sum += arr[i];

            // when subarray starts from index '0'
            if (sum == k)
                maxLen = i + 1;

            // make an entry for 'sum' if it is
            // not present in 'um'
            if (um.find(sum) == um.end())
                um[sum] = i;

            // check if 'sum-k' is present in 'um'
            // or not
            if (um.find(sum - k) != um.end())
            {

                // update maxLength
                if (maxLen < (i - um[sum - k]))
                    maxLen = i - um[sum - k];
            }
        }

        // required maximum length
        return maxLen;
    }
};
*/