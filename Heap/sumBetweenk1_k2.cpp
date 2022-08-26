#include <iostream>
#include <queue>
using namespace std;

int getSmallest(int arr[], int n, int k)
{
    priority_queue<int> pq; // max-heap
    for(int i= 0; i< n; i++){
        pq.push(arr[i]);
        if(pq.size() > k){
            pq.pop();
        }
    }

    return pq.top();
}

// driver code
int main()
{
    int n;
    cin>> n;
    int arr[n];
    for(int i= 0; i< n; i++){
        cin>> arr[i];
    }
    int k1, k2;
    cin>> k1>> k2;
    
    int sum = 0;
    int first = getSmallest(arr, n, k1);
    int second = getSmallest(arr, n, k2);

    for(int i= 0; i< n; i++){
        if(arr[i] > first and arr[i] < second)
            sum = sum + arr[i];
    }

    cout<< sum<< endl;
    // return 0;
}