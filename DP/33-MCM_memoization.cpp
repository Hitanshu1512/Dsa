#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits.h>
using namespace std;

int static t[101][101];    // depends on constraints i and j....100 & 100

int solve(int arr[], int i, int j)
{
    // initialize dp matrix
    bool flag = true;
        if(flag){
            memset(t, -1, sizeof(t));
            flag = false;
        }
    int ans = INT_MAX;

    // base condition
    if(i >= j)              // i = 1, j = n-1
        return 0;

    // check for stored value...
        if(t[i][j] != -1)
            return t[i][j];

    // use a loop to break at every k
    for(int k= i; k<= j-1; k++){     // or, for(int k= i+1; k< j; k++)
        int temp_ans = solve(arr, i, k) + solve(arr, k+1, j) + (arr[i-1]*arr[k]*arr[j]);
        ans = min(ans, temp_ans); // calculating answer from temporary answer
    }
    return t[i][j] = ans;
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