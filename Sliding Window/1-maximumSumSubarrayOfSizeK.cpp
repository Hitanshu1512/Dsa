#include <iostream>
#include <climits> // or #include <limits.h>
using namespace std;

int getMax(int arr[], int n, int k)     // Maximum Sum Subarray of size K | Sliding Window
{
    int i= 0, j= 0, sum= 0;
    int mx = INT_MIN;
    while(j < n){
        sum += arr[j];
        if((j-i+1) < k){
            j++;
        }
        else if ((j-i+1) == k){
            mx = max(mx, sum);
            sum = sum - arr[i];
            i++;
            j++;
        }
    }
    return mx;
}

int main()
{
    int n, k= 3; // k = size of window
    cin>> n;
    int arr[n];          
    for(int i= 0; i< n; i++)
        cin>> arr[i];
    
    int res = getMax(arr, n, k);
    cout<< res<< endl;

    return 0;
}
