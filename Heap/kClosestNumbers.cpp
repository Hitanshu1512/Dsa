#include<iostream>
#include <queue>
using namespace std;

void closestNum(int arr[], int n, int k, int x)
{
    priority_queue<pair<int, int>> maxh;    // f-> key (difference), s-> arr[i] (actual value)

    for(int i= 0; i< n; i++){
        maxh.push({abs(arr[i]-x), arr[i]}); // x is a number to which we need closest ones
        if(maxh.size() > k){
            maxh.pop();
        }
    }

    while(maxh.size() > 0){
        cout<< maxh.top().second<< " ";
        maxh.pop();
    }

    return;
}

// driver code
int main()
{
    int n, k, x;
    cin>> n>> k>> x;
    int arr[n];
    for(int i= 0; i< n;i++){
        cin>> arr[i];
    }

    closestNum(arr, n, k, x);

    return 0;
}