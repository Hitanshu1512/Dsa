#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        long long ans=0;
        priority_queue <long long,vector <long long>,greater <long long>> pq; //Min Heap
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        while(!pq.empty() and pq.size()>=2){
            long long p=pq.top();
            pq.pop();
            long long q=pq.top();
            pq.pop();
            ans+=p+q;
            pq.push(p+q);
        }
        return ans;
    }
};

// driver code
int main()
{
    long long n;
    cin >> n;
    
    long long i, arr[n];
    for(i = 0; i < n; i++)
        cin >> arr[i];
    
    Solution obj;
    cout<< obj.minCost(arr, n)<< endl;

    return 0;
}