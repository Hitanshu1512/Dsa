#include <bits/stdc++.h>
using namespace std;

int maxWater(int arr[], int n)
{
    int left_array[n];
    int right_array[n];
    int water[n];
    long long sum = 0;

    // MAXIMUM : left array of any i
    left_array[0] = arr[0];
    for(int i= 1; i< n; i++){
        left_array[i] = max(arr[i], left_array[i-1]);
    }

    // MAXIMUM : right array of any i
    right_array[n-1] = arr[n-1];
    for(int i= n-2; i>= 0; i--){
        right_array[i] = max(right_array[i+1], arr[i]);
    }

    // // Water at any given ndex i
    for(int i= 0; i< n; i++){
        water[i] = (min(left_array[i], right_array[i])) - arr[i];
    }

    // Sigma for trapped water for each i
    for(int i= 0; i< n; i++){
        sum += water[i];    // OR ---> sum = sum + ((min(left_array[i], right_array[i])) - arr[i]);
    }
    
    return sum;
}

int main()
{
    int n;
    cin>> n;

    int arr[n];
    for(int i= 0; i< n; i++)
        cin>> arr[i];   // 3 0 0 2 0 4

    cout<< maxWater(arr, n)<< endl;
    return 0;    
}