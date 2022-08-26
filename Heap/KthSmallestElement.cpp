#include<iostream>
#include <queue>
using namespace std;

int requireEle(int arr[], int n, int k)
{
    priority_queue<int> maxHeap;
    // Can be done by  sorting also in O(nlogn), but with heap -> O(nlogk) !
    for(int i= 0; i< n; i++){
        maxHeap.push(arr[i]);
        if(maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }

    return maxHeap.top();
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

    cout<< requireEle(arr, n, k)<< endl;
    return 0;
}