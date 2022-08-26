#include<iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> sorted(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> v;

    for(int i= 0; i< n; i++){
        minHeap.push(arr[i]);
        if(minHeap.size() > k){
            v.push_back(minHeap.top());
            minHeap.pop();
        }
    }

    while(minHeap.size() > 0){
            v.push_back(minHeap.top());
            minHeap.pop();
        }

    return v;
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

    vector<int> res = sorted(arr, n, k);

    for(auto it : res){
        cout<< it<< " ";
    }
    cout<< endl;

    return 0;
}