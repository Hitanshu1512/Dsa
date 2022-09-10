#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int solve(int arr[], int i, int j)
{
    int ans = INT_MAX;
    // base condition
    if(i >= j)              // i = 1, j = n-1
        return 0;

    // use a loop to break at every k
    for(int k= i; k<= j-1; k++){     // or, for(int k= i+1; k< j; k++)
        int temp_ans = solve(arr, i, k) + solve(arr, k+1, j) + (arr[i-1]*arr[k]*arr[j]);
        ans = min(ans, temp_ans); // calculating answer from temporary answer
    }
    return ans;
}

// driver code
int main()
{
    int n, i= 1;
    cin>> n;
    int j= n-1;
    int arr[n];
    for(int i= 0; i< n; i++)
        cin>> arr[i];
    
    cout<< solve(arr, i, j)<< endl;
    return 0;
}