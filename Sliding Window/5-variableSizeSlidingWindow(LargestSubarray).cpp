#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int i= 0, j= 0, sum= 0, mx= 0;
        while(j < N)
        {
            sum += A[j]; // calculating the sum
            
            if(sum < K)
                j++;
            else if(sum == K){
                // int size = j-i+1; // we will store maximum size of the window
                mx= max(mx, j-i+1);
                j++;
            }
            else if(sum > K){     // or 'else' only      
                while(sum > K){
                    sum = sum - A[i];
                    i++;
                }            
                j++;
            }
        }
        
        return mx;
    } 
};



int main()
{
    Solution obj;
    int n, k;
    cin>> n>> k;
    int arr[n];
    for(int i= 0; i< n; i++)
        cin>> arr[i];
    cout<< obj.lenOfLongSubarr(arr, n, k)<< endl;
    return 0;
}