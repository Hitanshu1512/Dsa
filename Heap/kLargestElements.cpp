#include <iostream>
#include <queue>
using namespace std;

void requireEle(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // Can be done by  sorting also in O(nlogn), but with heap -> O(nlogk) !
    
    for(int i= 0; i< n; i++){
        minHeap.push(arr[i]);
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }

    while(minHeap.size() > 0){
        cout<< minHeap.top()<< " ";
        minHeap.pop();
    }

    return;
}

// driver code
int main()
{
    int n, k;
    cin>> n>> k;
    int arr[n];
    for(int i= 0; i< n;i++){
        cin>> arr[i];
    }

    requireEle(arr, n, k);
    return 0;
}